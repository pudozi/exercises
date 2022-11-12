#include <stdio.h>

/* Exercise 1.18: Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#define MAX_SIZE  999+1

int readline(char buf[], int bufsize);
int stripws(char s[], int len);

int main()
{
    char line[MAX_SIZE];
    int len = 0;

    while ((len = readline(line, MAX_SIZE)) != 0) {
        /* if the line length exceeds the buffer size, it is possible for the
         * program to fail to strip the trailing blanks in a single pass as it
         * can remove at most only MAX_SIZE-1 blanks at once */
        if (len == MAX_SIZE-1 && line[MAX_SIZE-2] != '\n') {
            printf("%s", line);
            continue;
        }

        /* strip whitespace and print the line if it's not entirely blank */
        if (stripws(line, len) > 0 && line[0] != '\n') {
            printf("%s", line);
        }
    }

    return 0;
}

/* stripws: strip trailing whitespace from the end of a string, return new length */
int stripws(char s[], int len)
{
    /* set the index before the final newline or null terminator, remembering which */
    int i, newline;
    if (s[len-1] == '\n') {
        newline = 1;
        i = len - 2;
    } else {
        newline = 0;
        i = len - 1;
    }

    /* go backwards, stopping just before the first non-whitespace character */
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) --i;
    ++i;

    /* move the final newline and null terminator to the new position */
    if (newline) {
        s[i++] = '\n';
        s[i]   = '\0';
    } else {
        s[i]   = '\0';
    }

    return i;
}

/* readline: read a line into buf, return length */
int readline(char buf[], int bufsize)
{
    int i, ch;
    for (i = 0; i < bufsize-1 && (ch = getchar()) != EOF; ++i) {
        buf[i] = (char)ch;
        if (ch == '\n') {
            ++i;
            break;
        }
    }
    buf[i] = '\0';
     
    return i;
}

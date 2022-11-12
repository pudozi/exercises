#include <stdio.h>

/* Exercise 1.18: Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#define MAX_SIZE  999+1

int readline(char buf[], int bufsize);

int main()
{
    char line[MAX_SIZE];
    int len = 0;

    while ((len = readline(line, MAX_SIZE)) != 0) {
        /* if the line length exceeds the buffer size, it is possible for the
         * program to fail to strip the trailing blanks in a single pass as it
         * can remove at most only MAX_SIZE-1 blanks at once */
        if (len == MAX_SIZE-1 && line[MAX_SIZE-2] != '\n') {
            continue;
        }

        /* go backwards from the end of the line and move the newline (if it
         * exists) and null terminator behind the last non-blank character */
        int i, newline;
        if (line[len-1] == '\n') {
            newline = 1;
            i = len-2;
        } else {
            newline = 0;
            i = len-1;
        }
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) {
            --i;
        }
        if (newline) {
            line[i+1] = '\n';
            line[i+2] = '\0';
        } else {
            line[i+1] = '\0';
        }

        /* if the line isn't entirely blank, print it */
        if (line[0] != '\n') {
            printf("%s", line);
        }
    }

    return 0;
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

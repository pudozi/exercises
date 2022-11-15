#include <stdio.h>

/* Exercise 1.19: Write a function reverse(s) that reverses the character string
 * s.  Use it to write a program that reverses its input a line at a time. */

#define MAX_SIZE 999+1

int readline(char buf[], int bufsize);
void reverse(char s[]);
int slen(char s[]);

int main(void)
{
    char line[MAX_SIZE];
    int len = 0;

    /* reverse and print each line. note that if the line length exceeds the
     * buffer size, the program will produce incorrect output as it can reverse
     * at most only MAX_SIZE-1 characters at once. */
    while ((len = readline(line, MAX_SIZE)) != 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

/* readline: read a line into buf, return length */
int readline(char buf[], int bufsize)
{
    int i = 0, ch;
    while (i < bufsize-1 && (ch = getchar()) != EOF) {
        buf[i++] = (char)ch;
        if (ch == '\n') break;
    }
    buf[i] = '\0';
     
    return i;
}

/* reverse: reverse a string, preserving the final newline */
void reverse(char s[])
{
    int i = 0;
    int j = slen(s)-1;
    char temp;
    if (s[j] == '\n') --j;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i, --j;
    }
}

/* slen: return the length of a string, excluding the null terminator */
int slen(char s[])
{
    int i = 0;
    while(s[i] != '\0') ++i;
    return i;
}

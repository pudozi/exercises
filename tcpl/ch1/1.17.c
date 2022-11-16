#include <stdio.h>

/* Exercise 1.17: Write a program to print all input lines that are longer than
 * 80 characters. */

#define PRINT_LEN 81
#define BUFSIZE   PRINT_LEN+1

int readline(char buf[], int bufsize);

int main(void)
{
    char line[BUFSIZE];
    int len, ch;
    while ((len = readline(line, BUFSIZE)) != 0) {
        if (len == PRINT_LEN && line[PRINT_LEN-1] != '\n') {
            printf("%s", line);
            while ((ch = getchar()) != EOF) {
                putchar(ch);
                if (ch == '\n') break;
            }
        }
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

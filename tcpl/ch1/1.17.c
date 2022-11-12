#include <stdio.h>

/* Exercise 1.17: Write a program to print all input lines that are longer than
 * 80 characters. */

#define MAX_SIZE  999+1
#define PRINT_LEN 80

int readline(char buf[], int bufsize);

int main()
{
    char line[MAX_SIZE];
    int len = 0;

    while ((len = readline(line, MAX_SIZE)) != 0) {
        /* if line length exceeds buffer size, consume the rest and
         * remember only total length */
        if (len == MAX_SIZE-1 && line[MAX_SIZE-2] != '\n') {
            int ch;
            while ((ch = getchar()) != EOF) {
                ++len;
                if (ch == '\n') break;
            }
        }

        /* print the line if its length exceeds PRINT_LEN */
        if (len > PRINT_LEN) {
            printf("%d: %s", len, line);
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

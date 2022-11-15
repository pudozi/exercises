#include <stdio.h>

/* Exercise 1.16: Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and as much as
 * possible of the text. */

#define MAX_SIZE 999+1

int readline(char buf[], int bufsize);
int copystr(char dst[], char src[]);

int main(void)
{
    char lline[MAX_SIZE];
    char cline[MAX_SIZE];
    int llen = 0;
    int clen = 0;

    while ((clen = readline(cline, MAX_SIZE)) != 0) {
        /* if line length exceeds buffer size, consume the rest and
         * remember only total length */
        if (clen == MAX_SIZE-1 && cline[MAX_SIZE-2] != '\n') {
            int ch;
            while ((ch = getchar()) != EOF) {
                ++clen;
                if (ch == '\n') break;
            }
        }

        /* save line if longest thus far */
        if (clen > llen) {
            copystr(lline, cline);
            llen = clen;
        }
    }

    /* print what's available of the longest line */
    if (llen != 0) {
        printf("%d: %s", llen, lline);
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

/* copystr: copy a string from src to dst, return length */
int copystr(char dst[], char src[])
{
    int i = 0;
    while ((dst[i] = src[i]) != '\0') ++i;

    return i;
}

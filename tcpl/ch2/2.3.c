#include <stdio.h>

/* Exercise 2.3: Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value.  The allowable digits are 0 through 9, a through f, and A
 * through F. */

#define BUF_SIZE 500

int htoi(char s[]);
int readline(char buf[], int bufsize);

int main(void)
{
    char line[BUF_SIZE] = {0};

    while(readline(line, BUF_SIZE) != 0) {
        printf("%d\n", htoi(line));
    }

    return 0;
}

int htoi(char s[])
{
    int i = 0, n = 0;

    /* skip initial 0x or 0X */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i += 2;
    }

    while(1) {
        if (s[i] >= '0' && s[i] <= '9') {
            n *= 16, n += s[i] - '0';
        } else if (s[i] == 'a' || s[i] == 'A') {
            n *= 16, n += 10;
        } else if (s[i] == 'b' || s[i] == 'B') {
            n *= 16, n += 11;
        } else if (s[i] == 'c' || s[i] == 'C') {
            n *= 16, n += 12;
        } else if (s[i] == 'd' || s[i] == 'D') {
            n *= 16, n += 13;
        } else if (s[i] == 'e' || s[i] == 'E') {
            n *= 16, n += 14;
        } else if (s[i] == 'f' || s[i] == 'F') {
            n *= 16, n += 15;
        } else {
            break;
        }
        ++i;
    }

    return n;
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


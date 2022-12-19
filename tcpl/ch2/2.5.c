#include <stdio.h>

/* Exercise 2.5: Write the function any(s1,s2), which returns the first location
 * in the string s1 where any character from the string s2 occurs, or -1 if s1
 * contains no characters from s2. (The standard library function strpbrk does
 * the same job but returns a pointer to the location.) */

#define BUF_SIZE 999+1

int readline(char buf[], int bufsize);
int any(char s1[], char s2[]);

int main(void)
{
    char s1[BUF_SIZE], s2[BUF_SIZE];
    int i;

    while (readline(s1, BUF_SIZE) != 0 && readline(s2, BUF_SIZE) != 0) {
        i = any(s1, s2);
        printf("%d\n", i);
    }

    return 0;
}

/* any: return location in s1 of first character from s2 */
int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j);
        if (s2[j] != '\0') {
            return i;
        }
    }
    return -1;
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

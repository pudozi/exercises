#include <stdio.h>

/* Exercise 2.4: Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches any character in the string s2. */

#define BUF_SIZE 999+1

int readline(char buf[], int bufsize);
void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[BUF_SIZE], s2[BUF_SIZE];

    while (readline(s1, BUF_SIZE) != 0 && readline(s2, BUF_SIZE) != 0) {
        squeeze(s1, s2);
        printf("%s\n", s1);
    }

    return 0;
}

/* squeeze: remove in s1 all characters from s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; ++i) {
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; ++k);
        if (s2[k] == '\0') {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
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

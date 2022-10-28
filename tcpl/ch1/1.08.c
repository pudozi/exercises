#include <stdio.h>

/* Exercise 1.8: Write a program to count blanks, tabs, and newlines. */

int main()
{
    int ch;
    int bc = 0, tc = 0, lc = 0;

    /* count whitespace characters */
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') ++bc;
        else if (ch == '\t') ++tc;
        else if (ch == '\n') ++lc;
    }

    /* print results */
    printf("blanks: %d\n", bc);
    printf("tabs: %d\n",   tc);
    printf("lines: %d\n",  lc);

    return 0;
}

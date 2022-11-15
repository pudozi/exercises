#include <stdio.h>

/* Exercise 1.9: Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank. */

#define IN  1 /* inside a string of blanks */
#define OUT 0 /* outisde a string of blanks */

int main(void)
{
    int ch;
    int state = OUT;

    while ((ch = getchar()) != EOF) {
        if (ch != ' ') {
            if (state == IN) {
                state = OUT;
                putchar(' ');
            }
            putchar(ch);
        } else {
            state = IN;
        }
    }

    return 0;
}

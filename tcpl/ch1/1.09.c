#include <stdio.h>

/* Exercise 1.9: Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank. */

#define IN  1 /* inside a string of blanks */
#define OUT 0 /* outside a string of blanks */

int main(void)
{
    int ch;
    int state = OUT;

    while ((ch = getchar()) != EOF) {
        if (ch != ' ') {
            putchar(ch);
            if (state == IN) {
                state = OUT;
            }
        } else {
            if (state == OUT) {
                state = IN;
                putchar(' ');
            }
        }
    }

    return 0;
}

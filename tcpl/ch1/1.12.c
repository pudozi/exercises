#include <stdio.h>

/* Exercise 1.12: Write a program that prints its input one word per line. */

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int ch;
    int state = OUT;

    while ((ch = getchar()) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (state == IN) putchar('\n');
            state = OUT;
	} else {
            state = IN;
            putchar(ch);
        }
    }

    return 0;
}

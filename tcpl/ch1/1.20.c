#include <stdio.h>

/* Exercise 1.20: Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop.  Assume a fixed set of
 * tab stops, say every n columns.  Should n be a variable or a symbolic
 * parameter? */

#define TAB_WIDTH 8

int main()
{
    int ch;
    int tabstop = TAB_WIDTH;
    while ((ch = getchar()) != EOF) {
        if (ch == '\t') {
            while (tabstop-- != 0) putchar(' ');
            tabstop = TAB_WIDTH;
	} else {
            putchar(ch);
            if (ch == '\n' || --tabstop == 0) {
                tabstop = TAB_WIDTH;
            }
        }
    }
}

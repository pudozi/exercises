#include <stdio.h>

/* Exercise 1.21: Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.  Use the same
 * tab stops as for detab.  When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference? */

#define TAB_WIDTH 8

int main(void)
{
    int ch;
    int tabstop = TAB_WIDTH;
    int nspace = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            --tabstop, ++nspace;
            if (tabstop == 0) {
                if (nspace == 1) putchar(' ');
                else putchar('\t');
                tabstop = TAB_WIDTH, nspace = 0;
            }
        } else if (ch == '\t') {
            tabstop = TAB_WIDTH, nspace = 0;
            putchar('\t');
        } else {
            if (ch == '\n' || --tabstop == 0) {
                tabstop = TAB_WIDTH;
            }
            for (; nspace > 0; --nspace) putchar(' ');
            putchar(ch);
        }
    }
    for (; nspace > 0; --nspace) putchar(' ');

    return 0;
}

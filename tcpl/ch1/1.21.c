#include <stdio.h>

/* Exercise 1.21: Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.  Use the same
 * tab stops as for detab.  When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference? */

#define TAB_WIDTH 8

int main()
{
    int ch;
    int nspace = 0;
    int tabstop = TAB_WIDTH;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            ++nspace, --tabstop;
        } else if (ch == '\t') {
            nspace += tabstop;
            tabstop = 0;
        } else {
            if (ch != '\n') --tabstop;
            else tabstop = TAB_WIDTH;
            while (nspace > 0) {
                --nspace;
                putchar('_');
            }
            putchar(ch);
        }
        if (tabstop == 0) {
            if (nspace == 1) putchar(' ');
            else if (nspace > 1) putchar('\t');
            nspace = 0;
            tabstop = TAB_WIDTH;
        }
    }
}

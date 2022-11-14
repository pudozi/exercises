#include <stdio.h>

/* Exercise 1.21: Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.  Use the same
 * tab stops as for detab.  When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference? */

#define TAB_WIDTH 8

void printspace(int n, int ftab);

int main()
{
    int ch;
    int nspace = 0;
    int ftab = TAB_WIDTH;
    int ntab = TAB_WIDTH;
    while ((ch = getchar()) != EOF) {
        if (ch == ' ') {
            if (nspace == 0) {
                ftab = ntab;
            }
            ++nspace, --ntab;
        } else if (ch == '\t') {
            if (nspace == 0) {
                ftab = ntab;
            }
            nspace += ntab;
            ntab = TAB_WIDTH;
        } else {
            if (nspace != 0) {
                printspace(nspace, ftab);
                nspace = 0;
            }
            if (ch == '\n') {
                ntab = TAB_WIDTH;
            } else {
                --ntab;
            }
            putchar(ch);
        }
        if (ntab == 0) {
            ntab = TAB_WIDTH;
        }
    }
}

/* printspace: print n characters of space using tabs and spaces */
void printspace(int n, int ftab)
{
    if (n >= ftab) {
        putchar('\t');
        n -= ftab;
        ftab = TAB_WIDTH;
    }
    while (n >= TAB_WIDTH) {
        putchar('\t');
        n -= TAB_WIDTH;
    }
    while (n != 0) {
        putchar(' ');
        --n;
    }
}

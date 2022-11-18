#include <stdio.h>

/* Exercise 1.22: Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input.  Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 * */

#define TAB_WIDTH 8
#define MAX_COL   10
#define BUF_SIZE  MAX_COL+1 /* room for null */

int main(void)
{
    char word[BUF_SIZE] = {0};
    int wlen = 0, col = 0;
    int ch;
    int tabstop = TAB_WIDTH;

    while (1) {
        ch = getchar();
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != EOF) {
            /* break line on long words */
            if (col+wlen >= MAX_COL) {
                if (col != 0) {
                    putchar('\n');
                    col = 0;
                } else {
                    word[wlen] = '\0';
                    printf("%s\n", word);
                    col = 0;
                    wlen = 0;
                }
            }

            /* append character to word */
            word[wlen] = ch;
            ++wlen, --tabstop;
            if (tabstop == 0) tabstop = TAB_WIDTH;
        } else {
            /* print any words in the queu */
            if (wlen != 0) {
                if (col+wlen >= MAX_COL && col != 0 && ch != '\n') {
                    putchar('\n');
                    col = 0;
                }
                word[wlen] = '\0';
                printf("%s", word);
                col += wlen;
                wlen = 0;
            }

            /* print whitespace */
            if (ch == ' ') {
                ++col, --tabstop;
                if (tabstop == 0) tabstop = TAB_WIDTH;
                if (col <= MAX_COL) {
                    putchar(ch);
                } else {
                    col = 0;
                    putchar('\n');
                    putchar(ch);
                }
            } else if (ch == '\n') {
                putchar('\n');
                col = 0;
                tabstop = TAB_WIDTH;
            } else if (ch == '\t') {
                if (col+tabstop < MAX_COL) {
                    putchar('\t');
                    col += tabstop;
                    tabstop = TAB_WIDTH;
                } else {
                    while (col < MAX_COL) {
                        putchar(' ');
                        ++col, --tabstop;
                    }
                    putchar('\n');
                    col = 0;
                    while (tabstop > 0) {
                        putchar(' ');
                        ++col, --tabstop;
                    }
                    tabstop = TAB_WIDTH;
                }
            } else { /* eof */
                break;
            }
        }
    }
}


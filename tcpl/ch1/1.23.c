#include <stdio.h>

/* Exercise 1.23: Write a program to remove all comments from a c program.
 * Don't forget to handle quoted strings and character constants properly.  C
 * comments do not nest. */

void next(int c[]);
void del_multicomment(int c[]);
void del_singlecomment(int c[]);
void echo_quote(int c[]);

int main(void)
{
    int c[3] = {0};
    next(c);
    while (next(c), c[0] != EOF) {
        if (c[0] == '/') {
            if (c[1] == '*') {
                del_multicomment(c);
            } else if (c[1] == '/') {
                del_singlecomment(c);
            } else {
                putchar(c[0]);
            }
        } else if (c[0] == '\"' || c[0] == '\'') {
            echo_quote(c);
        } else {
            putchar(c[0]);
        }
    }

    return 0;
}

void next(int c[])
{
    c[0] = c[1];
    c[1] = getchar();
}

void del_multicomment(int c[])
{
    next(c);
    while (next(c), c[0] != '*' || c[1] != '/');
    putchar(' ');
    next(c);
}

void del_singlecomment(int c[])
{
    while (next(c), c[0] != '\n' && c[0] != EOF);
    putchar('\n');
}

void echo_quote(int c[])
{
    int term = c[0];
    putchar(term);
    while (next(c), c[0] != term && c[0] != EOF) {
        putchar(c[0]);
        if (c[0] == '\\') {
            next(c);
            putchar(c[0]);
        }
    }
    if (c[0] != EOF) putchar(term);
}

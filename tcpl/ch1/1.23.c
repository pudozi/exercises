#include <stdio.h>

/* Exercise 1.23: Write a program to remove all comments from a c[0] program.
 * Don't forget to handle quoted strings and character constants properly.  C
 * comments do not nest. */

void next(int c[]);

int main(void)
{
    int c[3] = {0};
    next(c);
    next(c);
    while (c[0] != EOF) {
        if (c[0] == '/') {
            /* multiline comment */
            if (c[1] == '*') {
                do {
                    next(c);
                } while ((c[0] != '*' || c[1] != '/') && c[0] != EOF);
                putchar(' ');
                next(c);
            /* singleline comment */
            } else if (c[1] == '/') {
                do {
                    next(c);
                } while (c[0] != '\n' && c[0] != EOF);
                putchar(' ');
                putchar('\n');
            } else {
                putchar(c[0]);
            }
        /* string */
        } else if (c[0] == '\"') {
                do {
                    putchar(c[0]);
                    next(c);
                    if (c[0] == '\\') {
                        putchar(c[0]);
                        next(c);
                    }
                } while (c[0] != '\"' && c[0] != EOF);
                putchar(c[0]);
        /* character constant */
        } else if (c[0] == '\'') {
                do {
                    putchar(c[0]);
                    next(c);
                    if (c[0] == '\\') {
                        putchar(c[0]);
                        next(c);
                    }
                } while (c[0] != '\'' && c[0] != EOF);
                putchar(c[0]);
        } else {
            putchar(c[0]);
        }
        next(c);
    }

    return 0;
}

void next(int c[])
{
    c[0] = c[1];
    c[1] = getchar();
}

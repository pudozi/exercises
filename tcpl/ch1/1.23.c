#include <stdio.h>

/* Exercise 1.23: Write a program to remove all comments from a c program.
 * Don't forget to handle quoted strings and character constants properly.  C
 * comments do not nest. */

int next(void);
int peak(void);
void del_multicomment(void);
void del_singlecomment(void);
void echo_quote(int quote);

int main(void)
{
    int c = next();
    while ((c = next()) != EOF) {
        if (c == '/') {
            if (peak() == '*') {
                del_multicomment();
            } else if (peak() == '/') {
                del_singlecomment();
            } else {
                putchar(c);
            }
        } else if (c == '\"' || c == '\'') {
            echo_quote(c);
        } else {
            putchar(c);
        }
    }

    return 0;
}

int c = EOF;

int next(void)
{
    int b = c;
    c = getchar();
    return b;
}

int peak(void)
{
    return c;
}

void del_multicomment(void)
{
    next();
    while (next() != '*' || peak() != '/');
    putchar(' ');
    next();
}

void del_singlecomment(void)
{
    int c;
    while (c = next(), c != '\n' && c != EOF);
    putchar('\n');
}

void echo_quote(int quote)
{
    int c;
    putchar(quote);
    while (c = next(), c != quote && c != EOF) {
        putchar(c);
        if (c == '\\') {
            putchar(next());
        }
    }
    if (c != EOF) putchar(quote);
}


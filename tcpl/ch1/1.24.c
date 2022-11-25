#include <stdio.h>

/* Exercise 1.24: Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets, and braces.  Don't forget
 * about quotes, both single and double, escape sequences, and comments. */

int next(void);
int peek(void);
int skip_blockcomment(void);
int skip_linecomment(void);
int skip_quote(int quote);

int main(void)
{
    int line = 1;
    int c = next();
    int braces = 0, brackets = 0, parentheses = 0;
    while ((c = next()) != EOF) {
        if (c == '/') {
            if (peek() == '*') {
                line += skip_blockcomment();
            } else if (peek() == '/') {
                line += skip_linecomment();
            }
        } else if (c == '\"' || c == '\'') {
            line += skip_quote(c);
        } else if (c == '\n') {
            ++line;
        } else if (c == '{') {
            ++braces;
        } else if (c == '}') {
            if (--braces < 0) {
                printf("error, line %d: encountered closing brace but no opening brace\n", line);
                ++braces;
            }
        } else if (c == '[') {
            ++brackets;
        } else if (c == ']') {
            if (--brackets < 0) {
                printf("error, line %d: encountered closing bracket but no opening bracket\n", line);
                ++brackets;
            }
        } else if (c == '(') {
            ++parentheses;
        } else if (c == ')') {
            if (--parentheses < 0) {
                printf("error, line %d: encountered closing parenthesis but no opening parenthesis\n", line);
                ++parentheses;
            }
        }
    }
    if (braces > 0) {
        printf("error: encountered more opening braces than closing braces\n");
    }
    if (brackets > 0) {
        printf("error: encountered more opening brackets than closing brackets\n");
    }
    if (parentheses > 0) {
        printf("error: encountered more opening parenthesis than closing parenthesis\n");
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

int peek(void)
{
    return c;
}

int skip_blockcomment(void)
{
    int lines = 0;
    int c;
    next();
    while (c = next(), c != '*' || peek() != '/') {
        if (c == EOF) {
            printf("error: expected end of block comment, encountered end of file\n");
            return lines;
        }
        if (c == '\n') {
            ++lines;
        }
    }
    next();
    return lines;
}

int skip_linecomment(void)
{
    int c;
    while (c = next(), c != '\n' && c != EOF);
    return 1;
}

int skip_quote(int quote)
{
    int lines = 0;
    int c;
    while ((c = next()) != quote) {
        if (c == EOF) {
            printf("error: expected end of quote, encountered end of file\n");
            return lines;
        }
        if (c == '\n') ++lines;
        if (c == '\\') next();
    }
    return lines;
}


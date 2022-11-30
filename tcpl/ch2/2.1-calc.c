#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Exercise 2.1: Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation.  Harder if you compute them:
 * determine the ranges of the various floating-point types. */

char char_min(void)
{
    char min = -1, prev = 0;
    while (min < prev && min != prev) {
        prev = min;
        min *= 2;
    }
    return prev;
}

char char_max(void)
{
    char max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

short short_min(void)
{
    short min = -1, prev = 0;
    while (min < prev && min != prev) {
        prev = min;
        min *= 2;
    }
    return prev;
}

short short_max(void)
{
    short max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

int int_min(void)
{
    int min = -1, prev = 0;
    while (min < prev && min != prev) {
        prev = min;
        min *= 2;
    }
    return prev;
}

int int_max(void)
{
    int max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

long long_min(void)
{
    long min = -1, prev = 0;
    while (min < prev && min != prev) {
        prev = min;
        min *= 2;
    }
    return prev;
}

long long_max(void)
{
    long max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

unsigned char uchar_max(void)
{
    unsigned char max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

unsigned short ushort_max(void)
{
    unsigned short max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

unsigned int uint_max(void)
{
    unsigned int max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

unsigned long ulong_max(void)
{
    unsigned long max = 1, prev = 0;
    while (max > prev && max != prev) {
        prev = max;
        max += max+1;
    }
    return prev;
}

void print_int_range(char type[], long min, unsigned long max)
{
    printf("%s: %ld to %lu\n", type, min, max);
}

int main(void)
{
    print_int_range("char", char_min(), char_max());
    print_int_range("short", short_min(), short_max());
    print_int_range("int", int_min(), int_max());
    print_int_range("long", long_min(), long_max());
    print_int_range("uchar", 0, uchar_max());
    print_int_range("ushort", 0, ushort_max());
    print_int_range("uint", 0, uint_max());
    print_int_range("ulong", 0, ulong_max());

    return 0;
}

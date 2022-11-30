#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Exercise 2.1: Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation.  Harder if you compute them:
 * determine the ranges of the various floating-point types. */

void print_int_range(char type[], long min, unsigned long max)
{
    printf("%s: %ld to %lu\n", type, min, max);
}

void print_float_range(char type[], double min, double max)
{
    printf("%s: %.1f to %.1f\n", type, min, max);
}

int main(void)
{
    print_int_range("char", CHAR_MIN, CHAR_MAX);
    print_int_range("short", SHRT_MIN, SHRT_MAX);
    print_int_range("int", INT_MIN, INT_MAX);
    print_int_range("long", LONG_MAX, LONG_MIN);
    print_int_range("uchar", 0, UCHAR_MAX);
    print_int_range("ushort", 0, USHRT_MAX);
    print_int_range("uint", 0, UINT_MAX);
    print_int_range("ulong", 0, ULONG_MAX);
    print_float_range("float", -FLT_MAX, FLT_MAX); 
    print_float_range("double", -DBL_MAX, DBL_MAX); 

    return 0;
}

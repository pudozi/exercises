#include <stdio.h>

/* Exercise 1.4: Write a program to print the corresponding Celsius to
 * Fahrenheit table. */

int main(void)
{
    float f, c;
    float min  =   0.0;
    float max  = 300.0;
    float step =  20.0;
    
    /* print heading */
    printf("cel   fah\n");
    printf("---------\n");
    
    /* print table */
    c = min;
    while (c <= max) {
        f = c*9.0/5.0+32;
        printf("%3.0f%6.1f\n", c, f);
        c += step;
    }

    return 0;
}


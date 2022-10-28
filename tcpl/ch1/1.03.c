#include <stdio.h>

/* Exercise 1.3: Modify the tempurature conversion program to print a heading
 * above the table */

int main()
{
    float f, c;
    float min  =   0;
    float max  = 300;
    float step =  20;
    
    /* print heading */
    printf("cel   fah\n");
    printf("---------\n");

    /* print table */
    f = min;
    while (f <= max) {
        c = (f-32.0)*5.0/9.0;
        printf("%3.0f%6.1f\n", f, c);
        f += step;
    }

    return 0;
}

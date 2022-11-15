#include <stdio.h>

/* Exercise 1.5: Modify the tempurature conversion program to print the table
 * in reverse order, that is, from 300 degrees to 0. */

int main(void)
{
    /* print heading */
    printf("fah   cel\n");
    printf("---------\n");

    /* print table */
    for (float f = 300; f >= 0; f -= 20) {
        printf("%3.0f%6.1f\n", f, (f-32)*5.0/9.0);
    }

    return 0;
}

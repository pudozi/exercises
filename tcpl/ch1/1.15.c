#include <stdio.h>

/* Exercise 1.15: Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion. */

float ftoc(float f);

int main()
{
    /* print header */
    printf("fah   cel\n");
    printf("--- -----\n");

    /* print table */
    for (float f = 0.0; f <= 300.0; f += 20) {
        printf("%3.0f %5.1f\n", f, ftoc(f));
    }

    return 0;
}

/* ftoc: convert a fahrenheit value to a celsius value */
float ftoc(float f)
{
    return (5.0/9.0)*(f-32);
}

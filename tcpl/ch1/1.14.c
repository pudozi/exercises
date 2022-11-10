#include <stdio.h>

/*  Write a program to print a histogram of the frequencies of different
 *  characters in its input. */

#define CHAR_COUNT    26+10 /* the number of characters to count */
#define MAX_HISTO_LEN 60    /* the maximum histogram bar length to print */

int main()
{
    int ch_freq[CHAR_COUNT] = {0};

    /* count character occurences */
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch >= '0' && ch <= '9') {
            ch_freq[ch-'0'] += 1;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch_freq[ch-'A'+10] += 1;
        } else if (ch >= 'a' && ch <= 'z') {
            ch_freq[ch-'a'+10] += 1;
        }
    }

    /* find the divisor for normalizing the frequencies to MAX_HISTO_LEN */
    int max_freq = 0;
    float divisor = 1;
    for (int i = 0; i < CHAR_COUNT; ++i) {
        if (ch_freq[i] > max_freq) {
            max_freq = ch_freq[i];
        }
    }
    if (max_freq > MAX_HISTO_LEN) {
        divisor = (float)max_freq / MAX_HISTO_LEN;
    }

    /* print horizontal histogram, normalizing if necessary */
    for (int i = 0; i < CHAR_COUNT; ++i) {
        /* normalize to MAX_HISTO_LEN */
        int norm_freq;
        if (divisor == 1.0) {
            norm_freq = ch_freq[i];
        } else {
            norm_freq = (float)ch_freq[i] / divisor;
        }

        /* print characters */
        if (i <= 9) {
            printf("%2c ", (char)i+'0');
        } else {
            printf("%c%c ", (char)i-10+'A', (char)i-10+'a');
        }

        /* print bar */
        for (int j = 0; j < norm_freq; ++j) {
            printf("█");
        }

        /* print frequency */
        if (norm_freq == 0) {
            printf("%d\n", ch_freq[i]);
        } else {
            printf(" %d\n", ch_freq[i]);
        }
    }

    return 0;
}

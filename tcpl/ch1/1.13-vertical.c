#include <stdio.h>

/* Exercise 1.13: Write a program to print a histogram of the lengths of words
 * in its input.  It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging. */

#define MAX_WORD_LEN  50 /* the maximum word length to be counted */
#define MAX_HISTO_LEN 20 /* the maximum histogram bar length to print */

int main(void)
{
    int wl_freq[MAX_WORD_LEN] = {0};

    /* count words by length */
    int ch;
    int wl = 0;
    while ((ch = getchar()) != EOF) {
        if (ch != ' ' && ch != '\t' && ch != '\n') {
            ++wl;
	} else {
            if (wl > 0) {
                if (wl < MAX_WORD_LEN) ++wl_freq[wl];
                wl = 0;
            }
        }
    }
    if (wl > 0 && wl < MAX_WORD_LEN) {
        ++wl_freq[wl];
    }

    /* find the divisor for normalizing the frequencies to MAX_HISTO_LEN */
    int max_freq = 0;
    float divisor = 1;
    for (int i = 1; i < MAX_WORD_LEN; ++i) {
        if (wl_freq[i] > max_freq) {
            max_freq = wl_freq[i];
        }
    }
    if (max_freq > MAX_HISTO_LEN) {
        divisor = (float)max_freq / MAX_HISTO_LEN;
    }

    /* print vertical histogram, normalizing if necessary */
    int histo_len = max_freq < MAX_HISTO_LEN ? max_freq : MAX_HISTO_LEN;
    for (int i = histo_len+1; i >= -1; --i) {
        for (int j = 1; j < MAX_WORD_LEN; ++j) {
            /* skip empty bars */
            if (wl_freq[j] == 0) continue;

            /* normalize to MAX_HISTO_LEN */
            int norm_freq;
            if (divisor != 1) {
                norm_freq = (float)wl_freq[j] / divisor;
            } else {
                norm_freq = wl_freq[j];
            }

            /* print header, bar or footer */
            if( i == norm_freq+1) printf("%2d ", wl_freq[j]);
            else if (i == 0) printf("-- ");
            else if (i == -1) printf("%2d ", j);
            else if (i <= norm_freq) printf("██ ");
            else printf("   ");
        }
        printf("\n");
    }

    return 0;
}

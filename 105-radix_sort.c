#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sort.h"

#define MAX_DIGITS 10

void radix_sort(int *array, size_t size) {
    int max = array[0];
    size_t i;
    int digits = 0;
    int j, k;
    int **buckets;
    int count[MAX_DIGITS];
    int idx;
    
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    while (max > 0) {
        max /= 10;
        digits++;
    }

    buckets = (int **)malloc(sizeof(int*) * MAX_DIGITS);

    for (i = 0; i < MAX_DIGITS; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * size);
    }


    for (k = 0; k < digits; k++) {
        for (i = 0; i < size; i++) {
            int num = array[i] / (int)pow(10, k) % 10;
            buckets[num][count[num]] = array[i];
            count[num]++;
        }

        idx = 0;

        for (i = 0; i < MAX_DIGITS; i++) {
            for (j = 0; j < count[i]; j++) {
                array[idx] = buckets[i][j];
                idx++;
            }
        }

        for (i = 0; i < MAX_DIGITS; i++) {
            count[i] = 0;
        }
    }

    for (i = 0; i < MAX_DIGITS; i++) {
        free(buckets[i]);
    }
    free(buckets);
}
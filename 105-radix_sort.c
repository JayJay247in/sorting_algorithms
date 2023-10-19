#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define MAX_DIGITS 10

void radix_sort(int *array, size_t size) {
  int max = array[0];
  for (size_t i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  
  int digits = 0;
  while (max > 0) {
    max /= 10;
    digits++;
  }

  int **buckets = malloc(sizeof(int*) * MAX_DIGITS);
  for (int i = 0; i < MAX_DIGITS; i++) {
    buckets[i] = malloc(sizeof(int) * size);
  }
  
  for (int k = 0; k < digits; k++) {
    int count[MAX_DIGITS] = {0};

    for (size_t i = 0; i < size; i++) {
      int num = (array[i] / ((int)pow(10, k)) % 10);
      buckets[num][count[num]] = array[i];
      count[num]++; 
    }

    printf("Sorting digit %d\n", k + 1);
    print_array(array, size);

    int idx = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
      for(int j = 0; j < count[i]; j++) {
        array[idx] = buckets[i][j];
        idx++;
      }
    }
  }

  for (int i=0; i < MAX_DIGITS; i++)
    free(buckets[i]);
  free(buckets);
}
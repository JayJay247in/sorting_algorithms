#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size) {

  size_t i;
  size_t j;
  int max;
  int *count;
  int idx;

  max = array[0];

  for (i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  count = malloc(sizeof(int) * (max + 1));
  
  for (idx = 0; idx <= max; idx++) {
    count[idx] = 0;
  }

  for (i = 0; i < size; i++) {
    count[array[i]]++;
  }

  printf("Counting array: ");
  
  for (idx = 0; idx <= max; idx++) {  
    printf("%d ", count[idx]);
  }

  printf("\n");

  j = 0;

  for (idx = 0; idx <= max; idx++) {
    while (count[idx] > 0) {
      array[j++] = idx;
      count[idx]--;
    }
  }

  free(count);

}
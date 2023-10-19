#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void counting_sort(int *array, size_t size) {
  int max = array[0];
  for (size_t i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i]; 
  }

  int *count = malloc(sizeof(int) * (max + 1));
  for (int i = 0; i <= max; i++)
    count[i] = 0;

  for (size_t i = 0; i < size; i++)
    count[array[i]]++;

  printf("Counting array: ");
  for (int i = 0; i <= max; i++)
    printf("%d ", count[i]);
  printf("\n");

  int j = 0;
  for (int i = 0; i <= max; i++) {
    while (count[i] > 0) {
      array[j++] = i;
      count[i]--;
    }
  }

  free(count);
}
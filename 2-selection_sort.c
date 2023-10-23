#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sort an array of integers using selection sort 
 * @array: The array to sort
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
  size_t i, j, min_idx;

  for (i = 0; i < size - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < size; j++) {
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      int tmp = array[i];
      array[i] = array[min_idx];
      array[min_idx] = tmp;
    }
  }
}
#include <stdio.h>
#include "sort.h"

void quick_sort(int *array, size_t size) {
  if (size < 2)
    return;

  int pivot = array[size - 1];
  int i = 0;
  for (size_t j = 0; j < size - 1; j++) {
    if (array[j] <= pivot) {
      if (i != j) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        
        // print array after swap
        for (size_t k = 0; k < size; k++) {
          printf("%d ", array[k]);
        }
        printf("\n");
      }
      i++;
    }
  }

  if (i != size - 1) {
    int tmp = array[i];
    array[i] = array[size - 1];
    array[size - 1] = tmp;
    
    // print array after swap
    for (size_t k = 0; k < size; k++) {
      printf("%d ", array[k]);
    }
    printf("\n");
  }

  quick_sort(array, i);
  quick_sort(array + i + 1, size - i - 1);
}
#include <stdio.h>
#include "sort.h"

void selection_sort(int *array, size_t size) {
  for (size_t i = 0; i < size - 1; i++) {
    int min = i;
    for (size_t j = i + 1; j < size; j++) {
      if (array[j] < array[min])
        min = j;
    }
    if (min != i) {
      int tmp = array[i];
      array[i] = array[min];
      array[min] = tmp;
      
      // print array after swap
      for (size_t k = 0; k < size; k++) {
        printf("%d ", array[k]); 
      }
      printf("\n");
    }
  }
}
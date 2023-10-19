#include <stdio.h>
#include "sort.h"

void bubble_sort(int *array, size_t size) {
  int swapped;
  do {
    swapped = 0;
    for (size_t i = 1; i < size; i++) {
      if (array[i - 1] > array[i]) {
        int temp = array[i];
        array[i] = array[i - 1]; 
        array[i - 1] = temp;
        swapped = 1;
        
        // print array after swap
        for (size_t j = 0; j < size; j++) {
          printf("%d ", array[j]);
        }
        printf("\n");
      }
    }
  } while (swapped);
}
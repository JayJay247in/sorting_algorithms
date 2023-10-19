#include <stdio.h>
#include "sort.h"

void bubble_sort(int *array, size_t size) {

  size_t i, j;
  int swapped;

  do {
    swapped = 0;
    for (i = 1; i < size; i++) {
      if (array[i - 1] > array[i]) {
        
        int temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
        
        swapped = 1;

        /*print array after swap*/
        for (j = 0; j < size; j++) {
          printf("%d ", array[j]);
        }
        printf("\n");
      }
    } 
  } while (swapped);

}
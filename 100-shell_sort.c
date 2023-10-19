#include <stdio.h>
#include "sort.h"

void shell_sort(int *array, size_t size) {
  int gap = 1;

  while (gap < size / 3) {
    gap = gap * 3 + 1;
  }

  while (gap >= 1) {
    for (int i = gap; i < size; i++) {
      int temp = array[i];
      int j = i;
      while (j >= gap && array[j - gap] > temp) {
        array[j] = array[j - gap];
        j -= gap;
      }
      array[j] = temp;
    }
    
    // Print array for current gap  
    printf("Gap: %d\n", gap);
    for (int i = 0; i < size; i++) {
      printf("%d ", array[i]);
    }
    printf("\n");

    gap /= 3; 
  }
}
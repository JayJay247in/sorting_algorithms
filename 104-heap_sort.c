#include <stdio.h>
#include "sort.h"

void siftDown(int *array, int root, int bottom, size_t size) {
  int maxChild;
  int done = 0;

  while ((root * 2 <= bottom) && (!done)) {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (array[root * 2] > array[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;

    if (array[root] < array[maxChild]) {
      int tmp = array[root];
      array[root] = array[maxChild];
      array[maxChild] = tmp;
      
      // Print array
      for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
      }
      printf("\n");

      root = maxChild;
    }
    else
      done = 1; 
  }
}

void heap_sort(int *array, size_t size) {
  for (int i = (size / 2); i >= 0; i--)
    siftDown(array, i, size - 1, size);

  for (int i = size - 1; i >= 0; i--) {
    int tmp = array[0];
    array[0] = array[i];
    array[i] = tmp;
    
    // Print array 
    for (int j = 0; j < size; j++) {
      printf("%d ", array[j]);
    }
    printf("\n");

    siftDown(array, 0, i - 1, size);
  }
}
#include <stdio.h>
#include <math.h>
#include "sort.h"

void bitonicMerge(int *array, size_t low, size_t cnt, size_t dir) {
  if (cnt > 1) {
    size_t k = cnt/2;
    for (size_t i = low; i < low + k; i++) {
      if (dir == (array[i] > array[i+k])) {
        int tmp = array[i];
        array[i] = array[i+k];
        array[i+k] = tmp;
      }
    }
    bitonicMerge(array, low, k, dir);
    bitonicMerge(array, low + k, k, dir);
  }
}

void bitonicSort(int *array, size_t low, size_t cnt, size_t dir) {
  if (cnt > 1) {
    size_t k = cnt/2;
    
    bitonicSort(array, low, k, 1);
    bitonicSort(array, low+k, k, 0);
    bitonicMerge(array,low, cnt, dir);
    
    // print array
    for (size_t i = 0; i < cnt; i++) {
      printf("%d ", array[low + i]);
    }
    printf("\n");
  }
}

void bitonic_sort(int *array, size_t size) {
  bitonicSort(array, 0, size, 1); 
}
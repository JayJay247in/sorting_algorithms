#include <stdio.h>
#include <math.h>
#include "sort.h"

/*
 * Merge two bitonic sequences in the array in the specified direction.
 * Returns 0 on success, non-zero on error.
*/ 
int bitonicMerge(int *array, size_t start, size_t length, int direction) {
  size_t i;
  size_t mid;

  if (array == NULL) 
    return 1;

  if (length <= 1) 
    return 0;

  mid = length / 2;

  /*Merge steps*/ 
  for (i = start; i < start + mid; i++) {
    if (direction == (array[i] > array[i+mid])) {
       /*Swap items*/
       int temp = array[i];
       array[i] = array[i+mid];
       array[i+mid] = temp;
    }
  }

  /*Recursion*/
  bitonicMerge(array, start, mid, direction); 
  bitonicMerge(array, start + mid, mid, direction);

  return 0;
}

/*
 * Sort array segment using bitonic sort algorithm.
 * Returns 0 on success.
*/
int bitonicSort(int *array, size_t start, size_t length, int direction) {
  size_t mid;

  /*Base case*/
  if (length <= 1)
    return 0;
  
  mid = length / 2;

  /*Recursively sort halves*/ 
  bitonicSort(array, start, mid, 1);
  bitonicSort(array, start + mid, mid, 0);

  /*Merge results*/
  bitonicMerge(array, start, length, direction); 

  return 0;
}

/*Driver function*/
void bitonic_sort(int *array, size_t size) {
  bitonicSort(array, 0, size, 1);
}
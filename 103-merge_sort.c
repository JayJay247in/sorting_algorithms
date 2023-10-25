#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, int *tmp, size_t left, size_t mid, size_t right) {

  size_t i = left, j = mid, k = left;

  while (i < mid && j <= right) {
    if (array[i] <= array[j])
      tmp[k++] = array[i++];
    else
      tmp[k++] = array[j++];
  }

  while (i < mid)
    tmp[k++] = array[i++];
  while (j <= right)
    tmp[k++] = array[j++];

  for (i = left; i <= right; i++)
    array[i] = tmp[i];
}


void top_down_split_merge(int *array, int *tmp, size_t left, size_t right) {

size_t mid;
mid = (left + right) / 2;
if (right <= left) return;

  top_down_split_merge(array, tmp, left, mid);
  top_down_split_merge(array, tmp, mid + 1, right);
  merge(array, tmp, left, mid + 1, right);
}

void merge_sort(int *array, size_t size) {
  int *tmp = malloc(sizeof(int) * size);
  top_down_split_merge(array, tmp, 0, size - 1);
  free(tmp);
}
#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int hoare_partition(int *array, int low, int high) {
  int pivot = array[high];
  int i = low - 1;
  int j = high + 1;

  while (1) {
    do {
      i++;
    } while(array[i] < pivot);

    do {
      j--;
    } while (array[j] > pivot);

    if (i >= j)
      return j;

    swap(&array[i], &array[j]);
    
    // Print array
    for (int k = 0; k < high + 1; k++) {
      printf("%d ", array[k]);
    }
    printf("\n");
  }
}

void quicksort(int *array, int low, int high) {
  if (low < high) {
    int p = hoare_partition(array, low, high);
    quicksort(array, low, p);
    quicksort(array, p + 1, high);
  }
}

void quick_sort_hoare(int *array, size_t size) {
  quicksort(array, 0, size - 1);
}
#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sort an array using the shell sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size) 
{
  size_t gap = 1;

  while (gap < size / 3) {
    gap = gap * 3 + 1; 
  }

  while (gap >= 1) {
    size_t i;
    for (i = gap; i < size; i++) {
      int temp = array[i];
      int j = i;

      while ((int)j >= (int)gap && array[j - gap] > temp) {
        array[j] = array[j - gap];
        j -= gap;
      }

      array[j] = temp;
    }
    
    print_array(array, size); 

    gap /= 3;
  }
}
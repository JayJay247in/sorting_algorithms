#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
  int array[] = {100, 93, 40, 57, 14, 58, 85, 54, 31, 56, 46, 39, 15, 26, 78, 13, 19, 48, 99, 81, 13, 52, 69, 73, 86, 7, 24, 35};
  size_t n = sizeof(array) / sizeof(array[0]);

  print_array(array, n);
  printf("\n");
  bitonic_sort(array, n);
  printf("\n");
  print_array(array, n);
  return (0);
}
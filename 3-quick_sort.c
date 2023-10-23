#include "sort.h"

/*Function prototypes*/
void swap(int *a, int *b);

void quick_sort(int *array, size_t size) {

  size_t i;
  int pivot;

  /*Move declarations to top*/
  pivot = array[size - 1];

  /*Declare i before loop*/
  for (i = 0; i < size - 1; i++) {
    
    /*Make types match*/
    if ((int)array[i] <= (int)pivot) {
      swap(&array[i], &array[size - 1]);
    }
  }

  /*Rest of function*/
  if (size > 1) {
  quick_sort(array, size - 1); 
}

}

/*Move function definition before calls*/
void swap(int *a, int *b) {

  int tmp = *a;
  *a = *b;  
  *b = tmp;

}
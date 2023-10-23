#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a listint_t linked list 
 *
 * @list: Pointer to head of linked list
 */
void print_list(const listint_t *list)
{
  while (list) {
    printf("%d\n", list->n);
    list = list->next;
  }
}
#include <stdio.h>
#include "sort.h"

/**
 * cocktail_sort_list - Sort a doubly linked list using cocktail sort
 * @list: Pointer to head of doubly linked list
 */
listint_t *start;
listint_t *i; 
listint_t *j;
listint_t *end;
int swapped;

void cocktail_sort_list(listint_t **list) {
  
  if (!list || !*list) return;

  start = *list;

  while (swapped) {
    swapped = 0;

    /*Forward pass*/
    for (i = start; i->next != end; i = i->next) {
      if (i->n > i->next->n) {
        swap_nodes(list, i, i->next);
        print_list(*list);
        swapped = 1;
      }
    }
    
    /*Update end*/
    end = start;

    /*Backward pass*/
    for (j = end->prev; j != start->prev; j = j->prev) {
      if (j->n > j->prev->n) {
        swap_nodes(list, j, j->prev);
        print_list(*list);
        swapped = 1;  
      }
    }

    /*Update start*/
    start = end;
  }

}
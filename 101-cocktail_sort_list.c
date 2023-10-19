#include <stdio.h>
#include "sort.h"

void cocktail_sort_list(listint_t **list) {
  if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;

  int swapped = 1; 
  listint_t *start = *list;
  listint_t *end = NULL;

  while (swapped) {
    swapped = 0;
    
    // Forward pass
    for (listint_t *i = start; i->next != end; i = i->next) {
      if (i->n > i->next->n) {
        listint_swap_nodes(i, i->next);
        print_list(*list);
        swapped = 1;
      }
    }
    end = start;

    // Backward pass
    for (listint_t *i = end->prev; i != start->prev; i = i->prev) {
      if (i->n > i->prev->n) {
        listint_swap_nodes(i, i->prev);
        print_list(*list);
        swapped = 1;
      }
    }
    start = end;
  }
}
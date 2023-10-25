#include <stdio.h>
#include "sort.h"

int swapped = 1;  
listint_t *i;
listint_t *j;
listint_t *start;
listint_t *end;

void cocktail_sort_list(listint_t **list) {
  if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;

  start = *list;
  end = NULL;

  while (swapped) {
    
    for (i = start; i->next != end; i = i->next) {
      if (i->n > i->next->n) {
        listint_swap_nodes(i, i->next);
        print_list(*list);
        swapped = 1;
      }
    }
    end = start;

    for (j = end->prev; j != start->prev; j = j->prev) {
      if (i->n > i->prev->n) {
        listint_swap_nodes(i, i->prev);
        print_list(*list);
        swapped = 1;
      }
    }
    start = end;
  }
}
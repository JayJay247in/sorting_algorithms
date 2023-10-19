#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list) {
  listint_t *current = NULL;

  if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;

  current = (*list)->next;  
  while (current != NULL) {
    while (current->prev != NULL && current->prev->n > current->n) {
      listint_t *tmp = current->prev;
      listint_swap_nodes(current->prev, current);
      print_list((*list));
      current->prev = tmp->prev;
      tmp->next = current->next;
      if (current->next != NULL) {
        current->next->prev = tmp;
      }
      current->next = tmp;
      print_list((*list));
    }
    current = current->next;
  }
}
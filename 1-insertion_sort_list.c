#include <stdio.h>
#include "sort.h" 

/**
 * insertion_sort_list - Sorts a listint_t doubly-linked list using insertion sort
 * @list: Pointer to the head of the listint_t list
 */
void insertion_sort_list(listint_t **list)
{
  listint_t *current;
  listint_t *tmp;

  if (list == NULL || *list == NULL)
    return;
  
  current = (*list)->next;
  
  while (current != NULL) {
    while (current->prev != NULL && current->n < current->prev->n) {
      tmp = current->prev;
      current->prev = tmp->prev;
      tmp->next = current->next;
      
      if (current->prev != NULL) {
        current->prev->next = current;  
      }
      else {
        *list = current;
      }
      
      if (tmp->next != NULL) {
        tmp->next->prev = tmp;
      }
      tmp->prev = current;
      current->next = tmp;
      
      print_list(*list);
      current = current->prev; 
    }
    
    current = current->next;
  }
}
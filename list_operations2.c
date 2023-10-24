#include "sort.h"

/**
 * swap_nodes - Swap positions of two nodes in a linked list 
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *temp;
    listint_t *temp2;
    
  /*Handle head/tail cases*/
  if (node1 == *list) {
    *list = node2;
  }
  if (node2->next == NULL) {
    node2->next = node1;
  }

  /*Swap next/prev pointers*/
  temp = node2->next;
  node2->next = node1->next;
  node1->next = temp;

  temp2 = node1->prev;
  node1->prev = node2->prev;
  node2->prev = temp2;

  /*Update neighbors*/
  if (node1->next != NULL) {
    node1->next->prev = node1; 
  }
  if (node2->prev != NULL) {
    node2->prev->next = node2;
  }
}
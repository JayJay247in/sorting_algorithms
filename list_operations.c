#include "sort.h"

/**
 * listint_swap_nodes - Swap two nodes in a listint_t linked list
 * @node1: Pointer to first node
 * @node2: Pointer to second node
 */
void listint_swap_nodes(listint_t *node1, listint_t *node2)
{
  if (node1->prev != NULL) {
    node1->prev->next = node2;
  } else {
    /*node1 is head*/
  }

  if (node2->next != NULL) {
    node2->next->prev = node1;
  } else {
    /*node2 is tail*/
  }

  /*Swap next/prev pointers*/
  node1->next = node2->next;
  node2->prev = node1->prev;
  node1->prev = node2;
  node2->next = node1;
}
#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

int compare_cards(const void *a, const void *b) {
  const deck_node_t *node_a = *(const deck_node_t **)a;
  const deck_node_t *node_b = *(const deck_node_t **)b;

  const char *value_a = node_a->card->value;
  const char *value_b = node_b->card->value;
  
  if (node_a->card->kind != node_b->card->kind)
    return node_a->card->kind - node_b->card->kind;
  
  if (value_a[0] == value_b[0]) {
    return value_a[1] - value_b[1]; 
  }

  return value_a[0] - value_b[0];
}

void sort_deck(deck_node_t **deck) 
{
  size_t n = 52;
  deck_node_t **nodes = malloc(sizeof(deck_node_t*) * n);

  deck_node_t *node = *deck;
  for (size_t i = 0; i < n; i++) {
    nodes[i] = node;
    node = node->next;
  }

  qsort(nodes, n, sizeof(deck_node_t*), compare_cards);

  for (size_t i = 0; i < n - 1; i++) {
    nodes[i]->next = nodes[i + 1];
    nodes[i + 1]->prev = nodes[i];
  }

  nodes[n - 1]->next = NULL;
  nodes[0]->prev = NULL;

  *deck = nodes[0];

  free(nodes);
}
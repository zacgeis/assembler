#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sym_table.h"

sym_table* new_sym_table() {
  sym_table* table = malloc(sizeof(sym_table));
  table->size = 0;
  table->head = NULL;
  table->tail = NULL;
  return table;
}

sym_table_node* new_sym_table_node(char* key, int val) {
  sym_table_node* node = malloc(sizeof(sym_table_node));
  node->next = NULL;
  node->key = key;
  node->val = val;
  return node;
}

void sym_table_insert(sym_table* table, char* key, int val) {
  sym_table_node* node = new_sym_table_node(key, val);
  sym_table_node* cur = table->head;
  table->size++;
  if(cur == NULL) {
    table->head = node;
    table->tail = node;
    return;
  }
  while (cur->next != NULL) {
    if (strcmp(cur->next->key, node->key) > 0) {
      node->next = cur->next;
      cur->next = node;
      return;
    }
    cur = cur->next;
  }
  table->tail->next = node;
  table->tail = node;
}

void sym_table_print(sym_table* l) {
  sym_table_node* cur = l->head;
  printf("size: %i\n", l->size);
  printf("conents: \n");
  while (cur != NULL) {
    printf("\t%s: %i\n", cur->key, cur->val);
    cur = cur->next;
  }
  printf("\n");
}

const sym_table_index* sym_table_build_index(sym_table* table) {
  sym_table_index* index = malloc(sizeof(sym_table_index));
  sym_table_node* nodes = malloc(sizeof(sym_table_node*) * table->size);
  sym_table_node* cur = table->head;
  for (int i = 0; i < table->size; i++) {
    nodes[i] = *cur;
    cur = cur->next;
  }
  index->nodes = nodes;
  index->size = table->size;
  return index;
}

sym_table_node* sym_table_find(sym_table_index* index, char* key) {
  return NULL;
}

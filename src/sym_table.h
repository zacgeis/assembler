#ifndef SYM_TABLE_H
#define SYM_TABLE_H

typedef struct sym_table_node {
  struct sym_table_node* next;
  char* key;
  int val;
} sym_table_node;

typedef struct sym_table_view {
  sym_table_node* nodes;
  int size;
} sym_table_view;

typedef struct sym_table {
  sym_table_node* head;
  sym_table_node* tail;
  int size;
} sym_table;

sym_table* new_sym_table();
void sym_table_insert(sym_table* table, char* key, int val);
void sym_table_print(sym_table* l);
const sym_table_view* sym_table_build_view(sym_table* table);
sym_table_node* sym_table_find(sym_table_view* index, char* key);

#endif

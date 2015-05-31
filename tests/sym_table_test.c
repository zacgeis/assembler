#include <stdio.h>
#include <string.h>

#include "sym_table.h"

int new_table_and_view_sorter_with_4_keys() {
  printf(".");

  sym_table* test = new_sym_table();

  sym_table_insert(test, "a", 1);
  sym_table_insert(test, "e", 5);
  sym_table_insert(test, "c", 3);
  sym_table_insert(test, "d", 4);

  const sym_table_view* view = sym_table_build_view(test);

  if (view->nodes[0].val != 1) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", view->nodes[0].val, 1);
    return 1;
  }
  if (view->nodes[1].val != 3) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", view->nodes[1].val, 3);
    return 1;
  }
  if (view->nodes[2].val != 4) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", view->nodes[2].val, 4);
    return 1;
  }
  if (view->nodes[3].val != 5) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", view->nodes[3].val, 5);
    return 1;
  }
  if (view->size != 4) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", view->size, 4);
    return 1;
  }

  return 0;
}

// Needs search test.

int sym_table_test() {
  if(new_table_and_view_sorter_with_4_keys() == 1) return 1;
  return 0;
}

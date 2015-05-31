#include <stdio.h>
#include <string.h>

#include "sym_table.h"

int new_table_and_index_sorter_with_4_keys() {
  printf(".");

  sym_table* test = new_sym_table();

  sym_table_insert(test, "a", 1);
  sym_table_insert(test, "e", 5);
  sym_table_insert(test, "c", 3);
  sym_table_insert(test, "d", 4);

  const sym_table_index* index = sym_table_build_index(test);

  if (index->nodes[0].val != 1) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", index->nodes[0].val, 1);
    return 1;
  }
  if (index->nodes[1].val != 3) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", index->nodes[1].val, 3);
    return 1;
  }
  if (index->nodes[2].val != 4) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", index->nodes[2].val, 4);
    return 1;
  }
  if (index->nodes[3].val != 5) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", index->nodes[3].val, 5);
    return 1;
  }
  if (index->size != 4) {
    printf("\n\nsym_table_test\n");
    printf("\tExpected %i to equal %i\n\n", index->size, 4);
    return 1;
  }

  return 0;
}

// Needs search test.

int sym_table_test() {
  if(new_table_and_index_sorter_with_4_keys() == 1) return 1;
  return 0;
}

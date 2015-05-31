#include <stdio.h>

#include "assembler_test.h"
#include "sym_table_test.h"

int fail() {
  printf("Failed test\n");
  return 1;
}

int main() {
  if(assembler_test() == 1) return fail();
  if(sym_table_test() == 1) return fail();
  printf("\nAll tests passed\n");
  return 0;
}

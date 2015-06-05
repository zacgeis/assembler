#include <stdio.h>
#include <string.h>

#include "assembler.h"

int convert_5_test() {
  printf(".");
  char* expected = "000000000000101";
  const char* result = strint_to_strbinary("5");

  if (strcmp(expected, result) != 0) {
    printf("\n\nConvert '5' to binary string\n");
    printf("\tExpected '%s' to equal '%s'\n\n", result, expected);
    return 1;
  }
  return 0;
}

int convert_16384_test() {
  printf(".");
  char* expected = "100000000000000";
  const char* result = strint_to_strbinary("16384");

  if (strcmp(expected, result) != 0) {
    printf("\n\nConvert '16384' to binary string\n");
    printf("\tExpected '%s' to equal '%s'\n\n", result, expected);
    return 1;
  }
  return 0;
}

int parse_a_inst_test() {
  printf(".");
  char* expected = "000000000000101";
  const instruction* in = parse_instruction("@5");
  const char* result = in->a.address;

  if (strcmp(result, expected) != 0) {
    printf("\n\nParse instruction '@5'\n");
    printf("\tExpected '%s' to equal '%s'\n\n", result, expected);
    return 1;
  }
  return 0;
}

int parse_a_inst_test_1024() {
  printf(".");
  char* expected = "000010000000000";
  const instruction* in = parse_instruction("@1024");
  const char* result = in->a.address;

  if (strcmp(result, expected) != 0) {
    printf("\n\nParse instruction '@5'\n");
    printf("\tExpected '%s' to equal '%s'\n\n", result, expected);
    return 1;
  }
  return 0;
}

int parse_c_inst_test_MP1() {
  printf(".");
  const instruction* in = parse_instruction("D=D-A;JGT");

  char* expected_a = "0";
  const char* result_a = in->c.a;

  char* expected_comp = "010011";
  const char* result_comp = in->c.comparison;

  char* expected_dest = "010";
  const char* result_dest = in->c.destination;

  if (strcmp(result_a, expected_a) != 0) {
    printf("\n\nParse instruction 'D=D-A;JGT'\n");
    printf("\tExpected '%s' to equal '%s'\n\n", result_a, expected_a);
    return 1;
  }

  if (strcmp(result_comp, expected_comp) != 0) {
    printf("\n\nParse instruction 'D=D-A;JGT'\n");
    printf("\tExpected '%s' to equal '%s'\n\n", result_comp, expected_comp);
    return 1;
  }

  if (strcmp(result_dest, expected_dest) != 0) {
    printf("\n\nParse instruction 'D=D-A;JGT'\n");
    printf("\tExpected '%s' to equal '%s'\n\n", result_dest, expected_dest);
    return 1;
  }

  return 0;
}

// Create a test for verifying the types.

int assembler_test() {
  if(convert_5_test() == 1) return 1;
  if(convert_16384_test() == 1) return 1;
  if(parse_a_inst_test() == 1) return 1;
  if(parse_a_inst_test_1024() == 1) return 1;
  if(parse_c_inst_test_MP1() == 1) return 1;
  return 0;
}

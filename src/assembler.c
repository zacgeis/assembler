#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "assembler.h"
#include "sym_table.h"

const char* CA0 = "0";
const char* CA1 = "1";

const char* CC101010 = "101010";
const char* CC111111 = "111111";
const char* CC111010 = "111010";
const char* CC001100 = "001100";
const char* CC110000 = "110000";
const char* CC001101 = "001101";
const char* CC110001 = "110001";
const char* CC001111 = "001111";
const char* CC110011 = "110011";
const char* CC011111 = "011111";
const char* CC110111 = "110111";
const char* CC001110 = "001110";
const char* CC110010 = "110010";
const char* CC000010 = "000010";
const char* CC010011 = "010011";
const char* CC000111 = "000111";
const char* CC000000 = "000000";
const char* CC010101 = "010101";

const char* CJD000 = "000";
const char* CJD001 = "001";
const char* CJD010 = "010";
const char* CJD011 = "011";
const char* CJD100 = "100";
const char* CJD101 = "101";
const char* CJD110 = "110";
const char* CJD111 = "111";

const instruction* parse_instruction(char* strinstruction) {
  instruction* parsed_instruction = malloc(sizeof(instruction));

  if (strinstruction[0] == '@') {
    const char* address = strint_to_strbinary(&strinstruction[1]);
    a_instruction i = { .address = address };
    parsed_instruction->type = TYPE_A;
    parsed_instruction->a = i;
  } else {
    char* comparison_part = malloc(sizeof(strinstruction));
    strcpy(comparison_part, strinstruction);
    comparison_part = strstr(comparison_part, "=") + 1;
    *index(comparison_part, ';') = '\0';

    char* destination_part = malloc(sizeof(strinstruction));
    strcpy(destination_part, strinstruction);
    *index(destination_part, '=') = '\0';

    char* jump_part = malloc(sizeof(strinstruction));
    strcpy(jump_part, strinstruction);
    jump_part = strstr(jump_part, ";") + 1;

    const char* a = c_instruction_a(comparison_part);
    const char* comparison = c_instruction_comparison(comparison_part);
    const char* destination = c_instruction_destination(destination_part);
    const char* jump = c_instruction_jump(jump_part);

    c_instruction i = {
      .a = a,
      .comparison = comparison,
      .destination = destination,
      .jump = jump
    };

    parsed_instruction->type = TYPE_C;
    parsed_instruction->c = i;

    //free(comparison_part);
    //free(destination_part);
    //free(jump_part);
  }

  return parsed_instruction;
}

const char* c_instruction_a(char* strpart) {
  if(strstr(strpart, "M") == NULL) {
    return CA0;
  }
  return CA1;
}

// D=D-A;JGT
const char* c_instruction_comparison(char* strpart) {
  if (strcmp(strpart, "0") == 0) {
    return CC101010;
  } else if (strcmp(strpart, "1") == 0) {
    return CC111111;
  } else if (strcmp(strpart, "-1") == 0) {
    return CC111010;
  } else if (strcmp(strpart, "D") == 0) {
    return CC001100;
  } else if (strcmp(strpart, "A") == 0 || strcmp(strpart, "M") == 0) {
    return CC110000;
  } else if (strcmp(strpart, "!D") == 0) {
    return CC001101;
  } else if (strcmp(strpart, "!A") == 0 || strcmp(strpart, "!M") == 0) {
    return CC110001;
  } else if (strcmp(strpart, "-D") == 0) {
    return CC001111;
  } else if (strcmp(strpart, "-A") == 0 || strcmp(strpart, "-M") == 0) {
    return CC110011;
  } else if (strcmp(strpart, "D+1") == 0) {
    return CC011111;
  } else if (strcmp(strpart, "A+1") == 0 || strcmp(strpart, "M+1") == 0) {
    return CC110111;
  } else if (strcmp(strpart, "D-1") == 0) {
    return CC001110;
  } else if (strcmp(strpart, "A-1") == 0 || strcmp(strpart, "M-1") == 0) {
    return CC110010;
  } else if (strcmp(strpart, "D+A") == 0 || strcmp(strpart, "D+M") == 0) {
    return CC000010;
  } else if (strcmp(strpart, "D-A") == 0 || strcmp(strpart, "D-M") == 0) {
    return CC010011;
  } else if (strcmp(strpart, "A-D") == 0 || strcmp(strpart, "M-D") == 0) {
    return CC000111;
  } else if (strcmp(strpart, "D&A") == 0 || strcmp(strpart, "D&M") == 0) {
    return CC000000;
  } else if (strcmp(strpart, "D|A") == 0 || strcmp(strpart, "D|M") == 0) {
    return CC010101;
  }

  printf("C_COMP_NULL");
  return NULL;
}

const char* c_instruction_destination(char* strpart) {
  if (strcmp(strpart, "M") == 0) {
    return CJD001;
  } else if (strcmp(strpart, "D") == 0) {
    return CJD010;
  } else if (strcmp(strpart, "MD") == 0) {
    return CJD011;
  } else if (strcmp(strpart, "A") == 0) {
    return CJD100;
  } else if (strcmp(strpart, "AM") == 0) {
    return CJD101;
  } else if (strcmp(strpart, "AD") == 0) {
    return CJD110;
  } else if (strcmp(strpart, "AMD") == 0) {
    return CJD111;
  }

  return CJD000;
}

const char* c_instruction_jump(char* strpart) {
  if (strcmp(strpart, "JGT") == 0) {
    return CJD001;
  } else if (strcmp(strpart, "JEQ") == 0) {
    return CJD010;
  } else if (strcmp(strpart, "JGE") == 0) {
    return CJD011;
  } else if (strcmp(strpart, "JLT") == 0) {
    return CJD100;
  } else if (strcmp(strpart, "JNE") == 0) {
    return CJD101;
  } else if (strcmp(strpart, "JLE") == 0) {
    return CJD110;
  } else if (strcmp(strpart, "JMP") == 0) {
    return CJD111;
  }

  return CJD000;
}

const char* strint_to_strbinary(char* strint) {
  int parsed_int = atoi(strint);
  char* binary_view = (char*) malloc(sizeof(char) * 16);
  binary_view[15] = '\0';
  for (int i = 14; i >= 0; i--) {
    int c = pow(2, i);
    if (parsed_int >= c) {
      parsed_int -= c;
      binary_view[14 - i] = '1';
    } else {
      binary_view[14 - i] = '0';
    }
  }

  return binary_view;
}

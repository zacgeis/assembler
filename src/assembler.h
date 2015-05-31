#ifndef ASSEMBLER_H
#define ASSEMBLER_H

typedef enum { TYPE_A, TYPE_C } instructionType;

typedef struct a_instruction {
  const char* address;
} a_instruction;

typedef struct c_instruction {
  const char* a;
  const char* comparison;
  const char* destination;
  const char* jump;
} c_instruction;

typedef struct instruction {
  instructionType type;
  // What would be the difference if these were pointers.
  union {
    a_instruction a;
    c_instruction c;
  };
} instruction;

const instruction* parse_instruction(char* strinstruction);
const char* c_instruction_a(char* strpart);
const char* c_instruction_comparison(char* strpart);
const char* c_instruction_destination(char* strpart);
const char* c_instruction_jump(char* strpart);
const char* strint_to_strbinary(char* strint);

#endif

BASE_SRC = $(wildcard src/*.c)
TESTS_SRC += $(wildcard tests/*.c)
FLAGS += -I src/ -I tests/

main: main.c
	@gcc -o bin/assembler ./main.c $(BASE_SRC) $(FLAGS)
	@./bin/assembler

test: tests/test.c
	@gcc -o bin/test $(BASE_SRC) $(TESTS_SRC) $(FLAGS)
	@./bin/test

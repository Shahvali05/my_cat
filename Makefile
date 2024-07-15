FLAGS = -std=c11 -Wall -Wextra -Werror
DIR_LIBS = libs
DIR_OBJ = obj
CMD = s21_cat

s21_cat: clean
	@mkdir -p $(DIR_OBJ)
	@gcc -c $(DIR_LIBS)/parser_flags.c -o $(DIR_OBJ)/parser_flags.o $(FLAGS)
	@gcc -c $(DIR_LIBS)/output.c -o $(DIR_OBJ)/output.o $(FLAGS)
	@gcc $(FLAGS) cat.c $(DIR_OBJ)/output.o $(DIR_OBJ)/parser_flags.o -o $(CMD)
test: $(CMD)
	@./test.sh
clean:
	@rm -rf $(CMD)
	@rm -rf $(DIR_OBJ)/parser_flags.o
	@rm -rf $(DIR_OBJ)/output.o

.PHONY: s21_cat

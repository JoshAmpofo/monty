#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void m_div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rota(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

/* error functions */
int usage_error(void);
int f_open_err(char *file);
int inv_ins_err(char *opcode, unsigned int line_number);
int malloc_error(void);
int pop_err(unsigned int line_number);
int pint_err(unsigned int line_number);
int short_stack_err(unsigned int line_number, char *op);
int div_err(unsigned int line_number);
int pchar_err(unsigned int line_number, char *message);
int intnum_err(unsigned int line_number);

/* interpreter functions */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
int run_monty(FILE *script_fd);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
void optoken_err(int error_code);

/* string-integer functions */
char *get_next_word(char *str, char *delims);
int get_word_count(char *str, char *delims);
int get_word_length(char *str, char *delims);
char **strtow(char *str, char *delims);
char *get_int(int n);
int is_delim(char ch, char *delims);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);


#endif /* MONTY_H */

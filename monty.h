#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>

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


void _fileop(char *file_name);
int _parse(char *buffer, int line_number, int format);
void _fileread(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);
stack_t *create_node(int n);
void _nodfree(void);
void _stackprnt(stack_t **, unsigned int);
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void _stackadd(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);
void function_call(op_func, char *, char *, int, int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void b_add(stack_t **, unsigned int);
void b_sub(stack_t **, unsigned int);
void b_div(stack_t **, unsigned int);
void b_mul(stack_t **, unsigned int);
void b_mod(stack_t **, unsigned int);
void ch_print(stack_t **, unsigned int);
void str_print(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void err(int error_code, ...);
void err_plus(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif

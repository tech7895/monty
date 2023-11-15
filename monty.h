#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: busue
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries busues through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void _bpush(stack_t **head, unsigned int number);
void _bpall(stack_t **head, unsigned int number);
void _bpint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void _bpop(stack_t **head, unsigned int counter);
void _bswap(stack_t **head, unsigned int counter);
void _badd(stack_t **head, unsigned int counter);
void _bnop(stack_t **head, unsigned int counter);
void _bsub(stack_t **head, unsigned int counter);
void _bdiv(stack_t **head, unsigned int counter);
void _bmul(stack_t **head, unsigned int counter);
void _bmod(stack_t **head, unsigned int counter);
void _bpchar(stack_t **head, unsigned int counter);
void _bpstr(stack_t **head, unsigned int counter);
void _brotl(stack_t **head, unsigned int counter);
void _brotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void _bqueue(stack_t **head, unsigned int counter);
void _bstack(stack_t **head, unsigned int counter);
#endif

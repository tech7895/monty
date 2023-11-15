#include "monty.h"


/**
 * _stackadd - This function adds a node to the stack
 * @new_node: the new node
 * @ln: the line number of of the opcode
 *
 * Return: void
 */
void _stackadd(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tempo;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tempo = head;
	head = *new_node;
	head->next = tempo;
	tempo->prev = head;
}


/**
 * _stackprnt - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void _stackprnt(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tempo = *stack;
	while (tempo != NULL)
	{
		printf("%d\n", tempo->n);
		tempo = tempo->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo;

	if (stack == NULL || *stack == NULL)
		err_plus(7, line_number);

	tempo = *stack;
	*stack = tempo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tempo);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		err_plus(6, line_number);
	printf("%d\n", (*stack)->n);
}

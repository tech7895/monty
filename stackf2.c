#include "monty.h"

/**
 * nop - This function performs a no-operation (NOP)
 * @stack: the top node of the stack
 * @line_number: the line number of of the opcode
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - This function swaps the top two elements of the stack
 * @stack: the top node of the stack
 * @line_number: the line number of of the opcode
 *
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_plus(8, line_number, "swap");
	tempo = (*stack)->next;
	(*stack)->next = tempo->next;
	if (tempo->next != NULL)
		tempo->next->prev = *stack;
	tempo->next = *stack;
	(*stack)->prev = tempo;
	tempo->prev = NULL;
	*stack = tempo;
}

/**
 * b_add - This adds the top two elements of the stack
 * @stack: the top node of the stack
 * @line_number: the line number of of the opcode
 */
void b_add(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_plus(8, line_number, "add");

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * b_sub - This adds the top two elements of the stack
 * @stack: the top node of the stack
 * @line_number: the line number of of the opcode
 *
 */
void b_sub(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_plus(8, line_number, "sub");

	(*stack) = (*stack)->next;
	add = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * b_div - This adds the top two elements of the stack
 * @stack: the top node of the stack.
 * @line_number: the line number of of the opcode
 *
 */
void b_div(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_plus(8, line_number, "div");

	if ((*stack)->n == 0)
		err_plus(9, line_number);
	(*stack) = (*stack)->next;
	add = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

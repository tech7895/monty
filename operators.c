#include "monty.h"

/**
 * b_mul - This function multiplies the top two elements of the stack
 * @stack: the top node of the stack
 * @line_number: the line number of of the opcode
 *
 * Return: void
 */
void b_mul(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_plus(8, line_number, "mul");

	(*stack) = (*stack)->next;
	add = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * b_mod - This function handles the modulo of top two elements of the stack
 * @stack: the top node of the stack
 * @line_number: the line number of of the opcode
 *
 */
void b_mod(stack_t **stack, unsigned int line_number)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		err_plus(8, line_number, "mod");


	if ((*stack)->n == 0)
		err_plus(9, line_number);
	(*stack) = (*stack)->next;
	add = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

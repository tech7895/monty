#include "monty.h"

/**
 * ch_print - This function prints the Ascii value
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode
 *
 * Return: void
 */
void ch_print(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * str_print - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void str_print(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tempo;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tempo = *stack;
	while (tempo != NULL)
	{
		ascii = tempo->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tempo = tempo->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tempo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tempo = *stack;
	while (tempo->next != NULL)
		tempo = tempo->next;

	tempo->next = *stack;
	(*stack)->prev = tempo;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tempo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tempo = *stack;

	while (tempo->next != NULL)
		tempo = tempo->next;

	tempo->next = *stack;
	tempo->prev->next = NULL;
	tempo->prev = NULL;
	(*stack)->prev = tempo;
	(*stack) = tempo;
}

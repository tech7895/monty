#include "monty.h"
/**
 * _bpint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _bpint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

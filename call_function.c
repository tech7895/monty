#include "monty.h"

/**
 * function_call - This function alls the required function
 * @func: a Pointer to the function
 * @op: a string representing the opcode
 * @val: the numeric value
 * @ln: the line numeber
 * @format: a format specifier
 *
 * Return: void
 */
void function_call(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int fl;
	int i;

	fl = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fl = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * fl);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

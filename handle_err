#include "monty.h"

/**
 * err - This function prints appropiate error messges
 * determined by their error code
 * @error_code: The error codes:
 * (1) => no input file or only one input file
 * (2) => The file can't be opened or read
 * (3) => The file contains invalid instruction
 * (4) => the program is unable to allocate memory
 * (5) => the parameter passed is not an int
 * (6) => the stack is empty for pint
 * (7) => the stack it empty for pop
 * (8) => the stack is too short
 *
 * Return: void
 */
void err(int error_code, ...)
{
	va_list g;
	char *op;
	int number_l;

	va_start(g, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(g, char *));
			break;
		case 3:
			number_l = va_arg(g, int);
			op = va_arg(g, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", number_l, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usge: push integer\n", va_arg(g, int));
			break;
		default:
			break;
	}
	_nodfree();
	exit(EXIT_FAILURE);
}

/**
 * err_plus - This function handles errors
 * @error_code: The error codes:
 *
 * (6) => the stack it empty for pint
 * (7) => the stack it empty for pop
 * (8) => the stack is too short for operation
 * (9) => zero denominator encountered
 */
void err_plus(int error_code, ...)
{
	va_list g;
	char *op;
	int number_l;

	va_start(g, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(g, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(g, int));
			break;
		case 8:
			number_l = va_arg(g, unsigned int);
			op = va_arg(g, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", number_l, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(g, unsigned int));
			break;
		default:
			break;
	}
	_nodfree();
	exit(EXIT_FAILURE);
}

/**
 * string_err - This function handles errors
 * @error_code: The error codes:
 * (10) ~> The number is outside ASCII bounds
 * (11) ~> empty stack
 *
 */
void string_err(int error_code, ...)
{
	va_list g;
	int number_l;

	va_start(g, error_code);
	number_l = va_arg(g, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", number_l);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", number_l);
			break;
		default:
			break;
	}
	_nodfree();
	exit(EXIT_FAILURE);
}

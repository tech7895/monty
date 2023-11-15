#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: 0 (Success)
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_fileop(argv[1]);
	_nodfree();

	return (0);
}

/**
 * create_node - This function creates a node
 * @n: the number of the node
 *
 * Return: a pointer to the node otherwise NULL
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * _nodfree - This frees nodes in the stack
 *
 */
void _nodfree(void)
{
	stack_t *tempo;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tempo = head;
		head = head->next;
		free(tempo);
	}
}


/**
 * add_to_queue - This adds a node to the queue
 * @new_node: the new node
 * @ln: the line number
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tempo->next != NULL)
		tempo = tempo->next;

	tempo->next = *new_node;
	(*new_node)->prev = tempo;

}

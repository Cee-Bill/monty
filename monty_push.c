#include "monty.h"
#include <ctype.h>
/**
 * check_digits - ensure a string contains digits only
 * @arg: string to check
 * Return: 0 if true | 1 if false
 */

static int check_digits(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * monty_push - opcode push pushes an element to the stack
 * @stack: node data structure for stack
 * @line_number: monty file line number
 * Return: void
 */

void monty_push(stack_t **stack, unsigned int line_number)
{
	long num;
	char *arg;

	arg = strtok(NULL, "\n\t\r");
	if (arg == NULL || check_digits(arg))
	{
		fprintf(stderr, "%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	/*num = atoi(arg);*/
	num = strtol(arg, NULL, 10);
	if (!node_add(stack, (int) num))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

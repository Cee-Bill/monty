#include "monty.h"

/**
 * main - program entry point
 * @argc: arguments count
 * @argv: argument vectors
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		read_file(argv[1], &stack);
	}
	free_stack(&stack);
	return (0);
}

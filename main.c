#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

var_t var;

void cleanup(void)
{
	free_buffer(0, var.buffer);
	free_stack(0, &var.stack);
	fd_close(0, var.fd);
}

/**
 * main - program entry point
 * @argc: arguments count
 * @argv: argument vectors
 * Return: EXIT_SUCCESS if successful
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	int line_number = 0;
	FILE *fd;
	size_t size = 0;
	char *buffer = NULL;
	char *line = NULL;

	var.queue = 0;
	var.stack_length = 0;
	var.buffer = NULL;
	var.stack = NULL;
	var.fd = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	var.fd = fd;
	/*_exit(free_buffer, &buffer);
	_exit(free_stack, &stack);
	_exit(fd_close, &fd); */
	atexit(cleanup);
	while (fgets(buffer, size, fd) != NULL)
	{
		line_number++;
		line = (strtok(buffer, "\n\t\r"));
		if (line != NULL && line[0] != '#')
		{
			process_opcode(line, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}


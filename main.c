#include "monty.h"

var_t var;

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
	on_exit(free_buffer, &buffer);
	on_exit(free_stack, &stack);
	on_exit(fd_close, &fd);
	while (getline(&buffer, &size, fd) != -1)
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
	 

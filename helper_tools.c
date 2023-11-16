#include "monty.h"

/**
 * read_file - reads a given file
 * @filename: character to read
 * @stack: Pointer to the top of the file
 */

void read_file(char *filename, stack_t **stack)
{
	FILE *fd;
	size_t size = 0;
	char *buffer = NULL;
	int counter = 0;

	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, fd) != EOF)
	{
		if (strcmp(buffer, "\n") != 0)
		{
			counter++;
			comp_str(buffer, stack, counter);
		}
		else if (strcmp(buffer, "\n") == 0)
			counter++;
	}
	fclose(fd);
	free(buffer);
}

/**
 * process_opcode - process monty opcode
 * @line: contains opcode and arguments
 * @stack: pointer to stack
 * @counter: Line number in the file
 * Return: pointer of the arrays
 */

void process_opcode(char *buffer, stack_t **stack, int counter)
{

}

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
 * tokenize - splits a string to different arguments
 * @input_string: argumemts to be tokenized
 * Return: Double pointer to the array of strings
 */

char **tokenize(char *input_string)
{
	int position = 0;
	char *token = NULL;
	char **tokens = NULL;

	tokens = malloc(sizeof(char *) * 64);
	if (tokens == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(input_string, " \n\t");
	if (token = NULL)
	{
		free(token);
		return (NULL);
	}
	while (token)
	{
		tokens[position] = token;
		token = strtok(NULL, " \n");
		position++;
	}
	free(token);
	return (tokens);
}

/**
 * process_opcode - process monty opcode
 * @buffer: contains opcode and arguments
 * @stack: pointer to stack
 * @counter: Line number in the file
 */

void process_opcode(char *buffer, stack_t **stack, int counter)
{
	char **tokens = NULL;
	int i = 0, unmatched_count = 0;

	instruction_t monty_ops[] = {
		{"push", monty_push};
		{"pall", monty_pall};
		{"pop", monty_pop};
		{"swap", monty_swap};
		{"pint", monty_pint};
		{"nop", monty_nop};
		{"add", monty_add};
		{"sub", monty_sub};
		{NULL, NULL};
	};
	tokens = tokenize(buffer);

	while (monty_ops[i].opcode != NULL && tokens[0] != NULL && verify_tokens(tokens) == 1)
	{
		if (strcmp(monty_ops[i].opcode, tokens[0]) == 0)
		{
			if (strcmp("pall", tokens[0]) == 0)
			{
				monty_ops[i].f(stack, counter);
			}
			else
			{
				num_error = atoi(tokens[1]);
				monty_ops[i].f(stack, counter);
				break;
			}
		}
		else
		{
			unmatched_count++;
		}
		i++;
	}
	if (unmatched_count == 8)
	{
		fprintf(stderr, "L%d: unknown instruction%s\n", counter, tokens[0]);
		free(tokens);
		exit(EXIT_FAILURE);
	}
	if ((strcmp("push", tokens[0]) == 0) && (verify_tokens(tokens) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		free(tokens);
		exit(EXIT_FAILURE);
	}
	free(tokens);
}

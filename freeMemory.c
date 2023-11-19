#include "monty.h"

/**
 * free_stack - free a stack
 * @status: exit status
 * @ptr: pointer to line
 */

void free_stack(int status, void *ptr)
{
	stack_t **stack;
	stack_t *next;

	(void)status;
	stack = (stack_t **)ptr;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_length = 0;
}

/**
 * free_buffer - free a buffer
 * @status: exit status
 * @ptr: pointer to line
 */
void free_buffer(int status, void *ptr)
{
	char **buffer = ptr;

	(void)status;
	if (*buffer != NULL)
		free(*buffer);
}

/**
 * fd_close - close a file
 * @status: exit status
 * @ptr: pointer to line
 */

void fd_close(int status, void *ptr)
{
	FILE *fd;

	(void)status;
	fd = (FILE *)ptr;
	fclose(fd);
}

#include "monty.h"

/**
 * monty_pall- prints all the values on the stack
 *              starting from the top of the stack.
 * @stack: node data struct for head stack
 * @line_number: file number
 */

void monty_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *curr_stack;

	curr_stack = *stack;

	while (curr_stack != NULL)
	{
		printf("%d\n", curr_stack->n);
		curr_stack = curr_stack->next;
		if (curr_stack == *stack)
			return;
	}

}

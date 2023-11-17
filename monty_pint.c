#include "monty.h"

/**
 * monty_pint - prints top element of the stack
 * @stack: pointer to the stack
 * @line_number: number of instruction
 * Return: void
 */

void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * monty_swap - swaps top 2 elements in the stack
 * @stack: pointer to the stack
 * @line_number: number of instruction
 * Return: void
 */

void monty_swap(stack_t **stack, unsigned int line_number)
{
	int swap_value = 0;

	if (*stack == NULL || (*stack)->n == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		swap_value = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = swap_value;
	}
}

/**
 * monty_push - pushes new elements into the stack
 * @stack: pointer to the stack
 * @line_number: number of instruction
 * Return: void
 */

void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	void(line_number);

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->n = num_error;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		new_node->n = num_error;
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
}

/**
 * monty_pop- removes top element from stack
 * @stack: pointer to the stack
 * @line_number: number of instruction
 * Return: void
 */

void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		*stack = current->next;
		(*stack)->prev = NULL;
		free(current);
	}
}

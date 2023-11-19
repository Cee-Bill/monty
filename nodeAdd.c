#include "monty.h"

/**
 * node_add - add a node to the top of the stack
 * or end of a queue
 * @stack: Pointer to the array of strings
 * @num: value to add to node
 * Return: the new node pointer, NULL otherwise
 */
stack_t *node_add(stack_t **stack, const int num)
{
	stack_t *new_node;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = num;
	if (*stack == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*stack)->prev->next = new_node;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}
	if (var.queue == STACK || var.stack_length == 0)
		*stack = new_node;
	return (new_node);
}

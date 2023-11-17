/**
 * monty_sub - Subtracts top element from the 2nd top in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int subtract_value = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	subtract_value = (*stack)->n;
	(*stack)->next->n -= subtract_value;
	*stack = aux->next;
	(*stack)->prev = NULL;
	free(aux);
}

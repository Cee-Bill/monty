#include "monty.h"

/**
 * process_opcode - process monty opcode
 * @buffer: contains opcode and arguments
 * @stack: pointer to stack
 * @line_number: Line number in the file
 */

void process_opcode(char *buffer, stack_t **stack, int line_number)
{
	int i = 0;
	instruction_t monty_ops[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"pint", monty_pint},
		{"nop", monty_nop},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{NULL, NULL}
	};

	for (i = 0; monty_ops[i].opcode != NULL; i++)
	{
		if (strcmp(monty_ops[i].opcode, buffer) == 0)
		{
			monty_ops[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, buffer);
	exit(EXIT_FAILURE);
}

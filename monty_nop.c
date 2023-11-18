#include "monty.h"

/**
*monty_nop - opcode nop doesn’t do anything
*@stack: node struct for stack head
*@line_number: line_number
*Return: void
*/

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

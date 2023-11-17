#include "monty.h"

/* implement push and pall opcode here 
 * void push(stack_t **stack, unsigned int line_number)
 * void pall(stack_t **stack, unsigned int line_number)
 *
 * receive variable from main.c for opcode argument (push or pull) 
 */

void pall(stack_t **stack_head, unsigned int line_number)
{
        (void)line_number;
        stack_t *curr_stack;

        curr_stack = *stack_head;

        while (curr_stack != NULL)
        {
                printf("%d\n", curr_stack->n);
                curr_stack = curr_stack->next;
        }
        
}

#include "monty.h"

/* pall- opcode pall prints all the values on the stack
 * starting from the top of the stack. 
 * @stack_head: node data struct for head stack
 * @line_number: file number
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

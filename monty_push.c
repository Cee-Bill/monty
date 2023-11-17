#include "monty.h"

/* implement push and pall opcode here 
 * void push(stack_t **stack, unsigned int line_number)
 * void pall(stack_t **stack, unsigned int line_number)
 *
 * receive variable from main.c for opcode argument (push or pull) 
 */

void push(stack_t **stack_head, unsigned int line_number)
{
        int tok_data_int;
        stack_t *new_node;
        
        if (tok_data[1] == NULL)
        {
                fprinf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        tok_data_int = atoi(tok_data[1]);

        new_node = malloc(sizeof(stackt));
        if (new_node == NULL)
        {
                fprintf(stderr, "Error: Malloc failed\n");
                exit(EXIT_FAILURE);
        }
        new_node->n = tok_data_int;
        new_node->prev = NULL;
        new_node->next = *stack_head;
        if (*stack_head != NULL)
                (*stack_head)->prev = new_node;
        *stack_head = new_node;
}

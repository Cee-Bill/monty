#include "monty.h"

/* push - opcode push pushes an element to the stack 
 * @stack_head: node data structure for stack
 * @line_number: monty file line number
 * Return: void
 */

void push(stack_t **stack_head, unsigned int line_number)
{
        int tok_data_int;
        stack_t *new_node;
        
        if (tokens[1] == NULL)
        {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        tok_data_int = atoi(tokens[1]);

        new_node = malloc(sizeof(stack_t));
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

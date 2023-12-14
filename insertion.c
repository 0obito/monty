#include "monty.h"

/**
 * push - Function to push a new node onto the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the command in the file
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, unsigned int line_number/*, int value*/)
{
    stack_t *new_node;

    (void)line_number;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /*new_node->n = value;*/
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
    new_node = NULL;
}

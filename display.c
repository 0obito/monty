#include "monty.h"

/**
 * pall - Function to print all the elements of the stack
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the command in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    (void)line_number;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}

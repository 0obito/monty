#include "monty.h"

/**
 * free_dlistint - a function that frees a dlistint_t list.
 *
 * @head: the header of a list.
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

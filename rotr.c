#include "monty.h"
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of te stack
 * @line_number: The line number being executed.
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *previous = NULL;
	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;

	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	previous->next = NULL;
	current->next = *stack;

	*stack = current;
}

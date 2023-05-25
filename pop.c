#include "monty.h"

/**
 * pop - Removes the op element of the stack
 * @stack: Dounle pointer to the head of the stack
 * @line_number: Line number of the instruction in the Monty file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

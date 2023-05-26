#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the instruction in the Monty file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

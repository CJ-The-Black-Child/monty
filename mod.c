#include "monty.h"

/**
 * mod - Computes the remainder of the division of the second top element by
 * the top element of the  stack
 * @stack: Double pointer to the head of the stack
 * @line_number: line number of the instruction in the monty file
 */

void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: divisio n by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
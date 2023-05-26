#include "monty.h"
/**
 * parseLine - Parses a line of input and executes the corresponding opcode.
 * @line: The line to parse
 * @stack: A pointer to the top of the stack
 * @line_number: The line number being parsed
 */

void parseLine(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int i;
	instruction_t opcodes[] = {
		{"add", add},
		{"nop", nop},
		{"pchar", pchar},
		{"rotr", rotr},
		{"rotl", rotl},
		{"pstr", pstr},
		{"mul", mul},
		{"div", stack_div},
		{"mod", mod},
		{"sub", sub},
		{"swap", swap},
		{"pop", pop},
		{"pint", pint},
		{"push", push},
		{"pall", pall},
		/* Here is where I added the opcode functions */
		{NULL, NULL}
	};
	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

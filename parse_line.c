#include "monty.h"
/**
 * parseLine -
 *
 * return:
 */

void parseLine(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	int i;
	instruction_t opcodes[] = {
		{"add", add},
		{"nop", nop},
		{"swap", swap},
		{"pop", pop},
		{"pint", pint},
		{"push", push},
		{"pall", pall},
		/* Here is where I added the opcode functions */
		{NULL, NULL}
	};
	opcode =strtok(line, " \t\n");
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

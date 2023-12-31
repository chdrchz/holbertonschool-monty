#include "monty.h"
/**
 * get_op - matches opcodes with functions
 *
 * @opcode: opcode to match to function
 * @stack: top of stack
 * @line_number: line number read from
 **/
void get_op(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

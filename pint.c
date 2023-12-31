#include "monty.h"
/**
 * pint - prints value at the top of the stack
 *
 * @stack: top of stack
 * @line_number: line number read from
 **/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

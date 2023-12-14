#include "monty.h"
/**
 * pall - prints all elements in stack
 *
 * @stack: top of stack
 * @line_number: line number read from
 **/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	while (*stack)
	{
		printf("%i\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}

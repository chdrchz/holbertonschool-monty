#include "monty.h"
/**
 * pop - removes top element in stack
 *
 * @stack: top of stack
 * @line_number: line number read from
 **/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *oldNode = NULL;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	oldNode = *stack;
	*stack = (*stack)->next;
	free(oldNode);
}

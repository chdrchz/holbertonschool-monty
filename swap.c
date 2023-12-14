#include "monty.h"
/**
 * swap - swaps top two elements of stack
 *
 * @stack: top of stack
 * @line_number: line number read from
 **/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *topNode = *stack;
	int temp;

	if (topNode == NULL || topNode->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = topNode->n;
	topNode->n = topNode->next->n;
	topNode->next->n = temp;
}

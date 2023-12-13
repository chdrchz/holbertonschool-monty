#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t topNode = NULL;
	int temp;

	if (topNode == NULL || topNode->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = topNode->n;
	topNode->n = topNode->next->n;
	topNode->next->n = temp;
}

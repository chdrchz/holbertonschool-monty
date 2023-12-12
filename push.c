#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *newNode;
	if (tokens[1] == NULL || !is_numeric(tokens[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(tokens[1]);
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->next = *stack;
	*stack = newNode;
}

int is_numeric(const char *str)
{
	int i = 0;
	if (str == NULL || *str == '\0')
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit((unsigned char)str[i]) && (i == 0 && str[i] != '-'))
			return (0);
	}
	return (1);
}

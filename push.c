#include "monty.h"
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *token;
	stack_t *newNode;
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \t\n");
	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(token);
	if (strspn(token, "0123456789") != strlen(token) && (token[0] != '-' || strlen(token) == 1))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = newNode;
	*stack = newNode;
}

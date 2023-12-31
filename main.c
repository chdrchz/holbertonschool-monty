#include "monty.h"
/**
 * main - open, read, and parse the monty file
 *
 * @argc: argument count
 * @argv: argument list
 *
 * Return: On success: EXIT_SUCCESS
 * On failure: EXIT_FAILURE
 **/
int main(int argc, char *argv[])
{
	char *line = NULL, *opcode;
	size_t length = 0;
	ssize_t read;
	unsigned int lineNumber = 1;
	stack_t *stack = NULL;
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read = getline(&line, &length, file);
	while (read != -1)
	{
		opcode = strtok(line, " \t\n");
		if (opcode == NULL)
		{
			lineNumber = lineNumber + 1;
			read = getline(&line, &length, file);
			continue;
		}
		get_op(opcode, &stack, lineNumber);
		read = getline(&line, &length, file);
		lineNumber = lineNumber + 1;
	}
	free(line);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
/**
 * free_stack - frees the stack memory
 *
 * @stack: top of stack
 * return: nothing
 **/
void free_stack(stack_t *stack)
{
	stack_t *nextNode;

	while (stack != NULL)
	{
		nextNode = stack->next;
		free(stack);
		stack = nextNode;
	}
}

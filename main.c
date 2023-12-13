#include "monty.h"

int main(int argc, char *argv[])
{
	char *line = NULL, *opcode;
	size_t length = 0;
	ssize_t read;
	unsigned int lineNumber;
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
	fclose(file);
	return (EXIT_SUCCESS);
}

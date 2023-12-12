#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{NULL, NULL}
};

int main(int argc, char *argv[])
{
	char *line = NULL, *token = NULL, *tokens[20];
	size_t length = 0;
	unsigned int lineNumber = 0;
	int i = 0, j = 0;
	FILE *file = NULL;
	globalStack = NULL;
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
	while (getline(&line, &length, file) != -1)
	{
		lineNumber++;
		i = 0;
		token = strtok(line, " /n/t");
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, " /n/t");
		}
		tokens[i] = NULL;
		for (j = 0; instructions[j].opcode != NULL; j++)
		{
			if (strcmp(tokens[0], instructions[j].opcode) == 0)
			{
				instructions[j].f(&globalStack, lineNumber);
				break;
			}
		}
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}

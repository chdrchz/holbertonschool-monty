#include "monty.h"
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t length = 0;
	unsigned int lineNumber = 0;
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
		token = strtok(line, " /n/t");
		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			token = strtok(NULL, " /n/t");
		}
		tokens[i] = NULL;
	}
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}

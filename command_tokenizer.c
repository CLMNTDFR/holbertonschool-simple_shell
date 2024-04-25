#include "main.h"

/**
* tokenizeCommand - Divide a string into tokens using delimiters
* @input: The string to tokenize
* Return: A pointer to an array of strings
*/
char **tokenizeCommand(char *input)
{
	char *token;
	char **args = NULL;
	int argCount = 0;

	args = malloc(sizeof(char *));
	if (args == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, " \t\n");

	while (token != NULL)
	{
		args[argCount] = strdup(token);
		if (args[argCount] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		argCount++;
		token = strtok(NULL, " \t\n");
		args = realloc(args, (argCount + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
	}
	args[argCount] = NULL;
	if (argCount == 0)
	{
		free(args);
		return (NULL);
	}
	return (args);
}

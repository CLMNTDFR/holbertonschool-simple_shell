#include "main.h"

/**
* executeCommand - Executes the specified command
* @command: The command string to be executed
* Return: 1 on successful execution
*/
int executeCommand(char *command)
{
	char **argument, *path;
	int index;

	argument = tokenizeCommand(command);
	if (argument == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (command[0] == '/' || command[0] == '.')
		path = strdup(command);
	else
		path = findCommandPath(argument[0]);

	if (path == NULL)
	{
		free(argument);
		perror("Error");
		exit(EXIT_FAILURE);
	}

	if (execve(path, argument, environ) == -1)
	{
		perror("Error in execve");
		for (index = 0; argument[index] != NULL; index++)
			free(argument[index]);
		free(path);
		free(argument);
		free(command);
		exit(EXIT_FAILURE);
	}
	free(path);
	free(argument);
	return (1);
}

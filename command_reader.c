#include "main.h"

/**
* readCommand - Reads a command from standard input
* Return: Command as a string
*/
char *readCommand(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
		printf("$ ");

	fflush(stdout);

	read = getline(&command, &size, stdin);
	if (read == -1)
	{
		free(command);
		return (NULL);
	}
	command[read - 1] = '\0';
	return (command);
}

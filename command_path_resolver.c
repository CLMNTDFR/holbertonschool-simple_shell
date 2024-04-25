#include "main.h"

/**
* findCommandPath - Finds the full path for the command
* @input: Command to find the path for
* Return: Full path as a string, or NULL if not found
*/
char *findCommandPath(char *input)
{
	char *path, *token, *copypath, *entirepath = NULL;
	int length;

	path = getenv("PATH");
	if (path == NULL || strlen(path) == 0)
		return (strdup(input));

	copypath = strdup(path);
	token = strtok(path, ":");

	while (token != NULL)
	{
		length = strlen(token) + strlen(input) + 2;
		entirepath = malloc(sizeof(char) * (length + 1));

		if (entirepath == NULL)
		{
			free(copypath);
			perror("Error in memory allocation");
			exit(EXIT_FAILURE);
		}

		strcpy(entirepath, token);
		strcat(entirepath, "/");
		strcat(entirepath, input);

		if (access(entirepath, F_OK | X_OK) == 0)
		{
			free(copypath);
			return (entirepath);
		}
		free(entirepath);
		token = strtok(NULL, ":");
	}
	free(copypath);
	return (strdup(input));
}

#include "main.h"

/**
* main - Entry point for the simple shell
* Return: Always returns 0
*/
int main(void)
{
	char *command = NULL, *command_start = NULL;
	int status = 0;
	pid_t pid;

	while (1)
	{
		command = readCommand();
		command_start = command;
		if (command == NULL)
		{
			free(command_start);
			exit(EXIT_SUCCESS);
		}

		while (command[0] == ' ' || command[0] == '\t')
			command++;
		if (command[0] == '\n' || command[0] == '\0')
		{
			free(command_start);
			continue;
		}

		if (strcmp(command, "exit") == 0)
		{
			free(command_start);
			exit(EXIT_SUCCESS);
		}

		pid = fork();

		if (pid == -1)
		{
			free(command);
			perror("Error");
		}

		else if (pid == 0)
		{
			executeCommand(command);
			free(command_start);
			exit(EXIT_SUCCESS);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
			free(command_start);
		}
	}
	return (0);
}

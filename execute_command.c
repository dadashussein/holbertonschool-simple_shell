#include "shell.h"
/**
 * execute_command - Execute a command.
 * @args: A pointer to a null-terminated array of strings.
 *
 * Return: Nothing.
 */
void execute_command(char **args)
{
	char *path;
	pid_t child_pid;
	int status;

	path = getenv("PATH");

	child_pid = fork();

	if (child_pid == -1)
		perror("fork");
	else if (child_pid == 0)
	{
		if (args[0])
		{
			if (strcmp(args[0], "echo") == 0 && strcmp(args[1], "$PATH") == 0)
				printf("%s\n", path);

			else
			{
				execvp(args[0], args);
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			perror("No command");
			exit(EXIT_FAILURE);
		}

		exit(0);
	}
	else
		wait(&status);
}

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

	clearenv();
	path = getenv("PATH");
	if (args[0] == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", args[0]);
		free(args);
		exit(127);
	}
	if (strcmp(args[0], "echo") == 0 && args[1] != NULL)
	{
		if (strcmp(args[1], "$PATH") == 0)
			printf("%s\n", path);
		else
		{
			if (strstr(args[1], "$") != NULL)
			{
				return;
			}
			else
				printf("%s\n", args[1]);
		}
		return;
	}
	child_pid = fork();
	if (child_pid == -1)
		perror("fork");
	else if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: %s: not found\n", args[0]);
			exit(127);
		}
		exit(EXIT_SUCCESS);
	}
	else
		wait(&status);
}

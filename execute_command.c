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

	char *name = args[0];

	path = getenv("PATH");

	if (name == NULL)
	{
		fprintf(stderr, "./hsh: %d: %s: not found\n", status, args[0]);
		return;
	}

	if (strcmp(name, "echo") == 0 && args[1] != NULL
		&& strcmp(args[1], "$PATH") == 0)	{
		printf("%s\n", path);
		return;
	}

	child_pid = fork();

	if (child_pid == -1)
		perror("fork");
	else if (child_pid == 0)
	{

		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", status, args[0]);
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}
	else
		wait(&status);
}

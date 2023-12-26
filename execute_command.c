#include "shell.h"

/**
 * execute_command_path - Execute a command with a given path.
 *
 * @args: A pointer to a null-terminated array of strings.
 * @path: A pointer to a string containing the path.
 *
 * Return: Nothing.
 */
void execute_command_path(char **args, char *path)
{
	char *token = strtok(path, ":");
	char *full_path;

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(args[0]) + 2);

		if (full_path == NULL)
		{
			perror("Error:");
			exit(EXIT_FAILURE);
		}

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, args[0]);

		if (execve(full_path, args, NULL) != -1)
		{
			free(full_path);
			exit(EXIT_SUCCESS);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "Command not found: %s\n", args[0]);
	exit(EXIT_FAILURE);
}

/**
 * execute_command - Execute a command.
 *
 * @args: A pointer to a null-terminated array of strings.
 *
 * Return: Nothing.
 */
void execute_command(char **args)
{
	pid_t child_pid;
	int status;
	char *path;

	child_pid = fork();

	if (child_pid == -1)
		perror("fork");
	else if (child_pid == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			path = getenv("PATH");
			execute_command_path(args, path);
		}
	}
	else
		wait(&status);
}

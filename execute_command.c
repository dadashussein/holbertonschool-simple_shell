#include "shell.h"
/**
 * handle_echo_command - Handle the echo command.
 *
 * @args: An array of strings containing the command and its arguments.
 * @path: The PATH environment variable.
 *
 * Return: Nothing.
 */
void handle_echo_command(char **args, char *path)
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
}
/**
 * execute_command - Execute a command.
 *
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */
void execute_command(char **args)
{
	char *path;
	pid_t child_pid;
	int status;

	path = getenv("PATH");

	if (args[0] == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", args[0]);
		free(args);
		exit(127);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(args[0], "echo") == 0 && args[1] != NULL)
	{
		handle_echo_command(args, path);
		return;
	}
	else if (args != NULL)
	{
		child_pid = fork();

		if (child_pid == -1)
			perror("fork");
		else if (child_pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				fprintf(stderr, "./hsh: %s: bulunamadı\n", args[0]);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status);
	}
}

#include "shell.h"
/**
 * handle_echo_command - Handle the echo command.
 * @args: An array of strings containing the command and its arguments.
 * @path: The PATH environment variable.
 *
 * Return: Nothing.
 */
void handle_echo_command(char **args, char *path)
{
	if (strcmp(args[1], "$PATH") == 0)
		printf("%s\n", path);
	else if (strstr(args[1], "$") == NULL)
		printf("%s\n", args[1]);
}

/**
 * handle_exit_command - Handle the exit command.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */
int handle_exit_command(char **args)
{
	free(args);
	exit(EXIT_SUCCESS);
}

/**
 * handle_child_process - Handle the exit command.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */
int handle_child_process(char **args)
{
	if (execvp(args[0], args) == -1)
	{
		fprintf(stderr, "./hsh: %s: bulunamadı\n", args[0]);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

/**
 * handle_parent_process - Handle the exit command.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */
int handle_parent_process(pid_t child_pid)
{
	int status;

	waitpid(child_pid, &status, 0);
	return (WEXITSTATUS(status));
}

/**
 * execute_command - Handle the exit command.
 * @args: An array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */
int execute_command(char **args)
{
	char *path;
	pid_t child_pid;

	path = getenv("PATH");

	if (args[0] == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", args[0]);
		free(args);
		return (127);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		return (handle_exit_command(args));
	}
	if (strcmp(args[0], "echo") == 0 && args[1] != NULL)
	{
		handle_echo_command(args, path);
		return (0);
	}
	else if (args != NULL)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (child_pid == 0)
		{
			return (handle_child_process(args));
		}
		else
		{
			return (handle_parent_process(child_pid));
		}
	}

	return (0);
}

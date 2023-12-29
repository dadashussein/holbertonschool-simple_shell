#include "shell.h"
/**
 * handle_echo_command - Handle the exit command.
 * @args: An array of strings containing the command and its arguments.
 * @path: An array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */
void handle_echo_command(char **args, char *path)
{
	if (path == NULL)
	{
		fprintf(stderr, "./hsh: PATH environment variable not set\n");
		return;
	}

	if (strncmp(args[1], "$PATH", 5) == 0)
		printf("%s\n", path);
	else
	{
		char *env_var = args[1];
		char *dollar_sign = strchr(env_var, '$');

		/* If there is no dollar sign in env_var or it's at the end */
		if (dollar_sign != NULL)
		{
			env_var = dollar_sign + 1;
			printf("%s\n", getenv(env_var));
		}
		else
			printf("%s\n", args[1]);
	}
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
 * @path: path
 *
 * Return: Nothing.
 */
int handle_child_process(char *path, char **args)
{
	char *full_path = find_command_in_path(path, args[0]);

	if (full_path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		exit(127);
	}

	execv(full_path, args);
	perror("execv");
	exit(127);
}

/**
 * handle_parent_process - Handle the exit command.
 * @child_pid: An array of strings containing the command and its arguments.
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

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: PATH environment variable not set\n");
		return (127);
	}

	if (args[0] == NULL)
	{
		fprintf(stderr, "./hsh: %s: not found\n", args[0]);
		free(args);
		return (127);
	}
	if (strcmp(args[0], "exit") == 0)
		return (handle_exit_command(args));

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
			return (handle_child_process(path, args));
		else
			return (handle_parent_process(child_pid));
	}

	return (0);
}

#include "shell.h"
/**
 * simple_shell - Simple shell
 * @command: Command to execute
 *
 * Return: Nothing
 */
void simple_shell(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
		exit(EXIT_FAILURE);

	else if (pid == 0)
	{
		char *args[2];

		if (command == NULL)
			command = "/bin/ls";

		args[0] = command;
		args[1] = NULL;

		execve(command, args, environ);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
}

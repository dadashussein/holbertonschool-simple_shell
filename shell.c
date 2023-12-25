#include "shell.h"
/**
 * simple_shell - Simple shell
 * @command: Command to execute
 *
 * Return: Nothing
 */
void simple_shell(char *command)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[2];

		if (command == NULL)
			command = "/bin/ls";

		args[0] = command;
		args[1] = NULL;

		execve(command, args, environ);
		perror("");
		exit(EXIT_FAILURE);
	}
	else
	{
		wpid = waitpid(pid, &status, 0);

		if (wpid == -1)
		{
			perror("Wait error");
			exit(EXIT_FAILURE);
		}
		exit(WEXITSTATUS(status));
	}
}

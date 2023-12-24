#include "shell.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{

	char buffer[BUFFER_SIZE];
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		if (!fgets(buffer, BUFFER_SIZE, stdin))
			break;
		buffer[strcspn(buffer, "\n")] = '\0';

		if (strlen(buffer) == 0)
			continue;

		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			char **args = malloc(BUFFER_SIZE);

			args[0] = buffer;
			args[1] = NULL;

			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				exit(1);
			}

			free(args);
		}
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}


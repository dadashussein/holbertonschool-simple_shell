#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256

int main()
{
	char buffer[BUFFER_SIZE];
	pid_t pid;

	while (1)
	{
		printf("#cisfun$ ");
		if (!fgets(buffer, BUFFER_SIZE, stdin))
			break;
		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
			break;
		if (strlen(buffer) == 0)
			continue;
		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		/*child process*/
		if (pid == 0)
		{
			if (execl(buffer, buffer, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		/*parent process*/
		else
			waitpid(pid, NULL, 0);
	}
	return (0);
}


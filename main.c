#include "shell.h"
/**
 * main - Entry point.
 *
 * Return: 0 on success, otherwise 1.
 */
int main(void)
{
	int i = 0, status = 0;
	char *line = NULL;
	char **args = NULL;

	while (1)
	{
		line = read_command();
		if (!line)
			break;

		args = parse_command(line, " \n\t");
		free(line);
		if (!args[0])
		{
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			continue;
		}
		else if (strcmp(args[0], "exit") == 0 && args[1] == NULL)
		{
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			exit(status);
		}
		else if (strcmp(args[0], "env") == 0)
		{
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			print_env();
			continue;
		}

		status = execute_command(args);

		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
	free(line);
	if (status)
		exit(status);

	return (0);
}

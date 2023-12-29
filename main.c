#include "shell.h"
/**
 * main - Base functionality of shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	char *line;
	char **args;

	while (1)
	{
		line = read_command();
		if (!line)
			break;

		args = parse_command(line);
		free(line);
		if (!args[0])
		{
			free(args);
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			break;
		}

		execute_command(args);

		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}

	return (0);
}

#include "shell.h"
/**
 * main - A simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	char *line;
	char **args;
	builtin_t builtin_table[] = {
		{"exit", exit_builtin},
		{NULL, NULL}};

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

		for (i = 0; builtin_table[i].name; i++)
		{
			if (strcmp(args[0], builtin_table[i].name) == 0)
			{
				builtin_table[i].func(args);
				goto free_args;
			}
		}
		execute_command(args);

free_args:
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
	}

	free(line);
	return (0);
}

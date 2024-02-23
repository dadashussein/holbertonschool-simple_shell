#include "shell.h"
/**
 * read_command - Read a command line from standard input.
 *
 * Return: A pointer to a string containing the command line.
 */
char *read_command(void)
{
	char *line = NULL;
	char *prompt = "$ ~";
	size_t line_size = 0;
	printf("%s ", prompt);
	if (getline(&line, &line_size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}

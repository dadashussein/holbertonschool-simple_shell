#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
/**
 * read_command - Read command from stdin
 *
 * Return: Pointer to command
 */
char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&command, &len, stdin);
	if (read == -1)
		exit(EXIT_FAILURE);

	command[strcspn(command, "\n")] = '\0';

	return (command);
}


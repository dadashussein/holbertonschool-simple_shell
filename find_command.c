#include "shell.h"
/**
 * find_command_in_path - Handle the exit command.
 * @path: An array of strings containing the command and its arguments.
 * @command: An array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */
char *find_command_in_path(char *path, char *command)
{
	char *token, *path_copy = strdup(path);

	for (token = strtok(path_copy, ":"); token != NULL; token = strtok(NULL, ":"))
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
	}

	free(path_copy);
	return (NULL);
}

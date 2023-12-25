#include "shell.h"
/**
 * parse_command - Parse a command line into arguments.
 *
 * @line: A pointer to a string containing the command line.
 *
 * Return: A pointer to a null-terminated array of strings.
 */
char **parse_command(char *line)
{
	int token_count = 0;
	char *token;
	char **tokens = malloc(strlen(line) * sizeof(char *));

	if (!tokens)
		return (NULL);

	token = strtok(line, " \n\t");

	while (token)
	{
		tokens[token_count] = strdup(token);
		if (!tokens[token_count])
		{
			free(tokens[token_count]);
			fprintf(stderr, "Error happens.");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, " \n\t");
	}

	tokens[token_count] = NULL;

	return (tokens);
}

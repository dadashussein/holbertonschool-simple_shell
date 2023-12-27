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
	int numWords = 0;
	char *token;
	char **wordsArray = malloc(strlen(line) * sizeof(char *));

	if (!wordsArray)
		return (NULL);

	token = strtok(line, " \n\t");

	while (token)
	{
		wordsArray[numWords] = strdup(token);
		if (!wordsArray[numWords])
		{
			free(wordsArray[numWords]);
			fprintf(stderr, "Error happens.");
			exit(EXIT_FAILURE);
		}
		numWords++;
		token = strtok(NULL, " \n\t");
	}

	wordsArray[numWords] = NULL;

	return (wordsArray);
}

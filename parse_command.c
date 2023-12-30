#include "shell.h"
/**
 * parse_command - Parse the command line.
 * @line: The command line.
 * @delimiter: The delimiter.
 *
 * Return: The array of words.
 */
char **parse_command(char *line, char *delimiter)
{
	int numWords = 0;
	char *token;
	char **wordsArray = malloc(strlen(line) * sizeof(char *));

	if (!wordsArray)
		return (NULL);

	token = strtok(line, delimiter);

	while (token)
	{
		wordsArray[numWords] = strdup(token);
		if (!wordsArray[numWords])
		{
			free(wordsArray[numWords]);
			free(wordsArray);
			fprintf(stderr, "Error happens.");
			exit(EXIT_FAILURE);
		}
		numWords++;
		token = strtok(NULL, delimiter);
	}

	wordsArray[numWords] = NULL;
	free(token);
	return (wordsArray);
}

#include "shell.h"
/**
 * exit_builtin - exit yerleşik öğesini uygular.
 * @args: A pointer to a null-terminated array of strings.
 *
 * Return: Nothing.
 */
int exit_builtin(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		fprintf(stderr, "exit: too many arguments\n");
		return (2);
	}

	status = args[0] ? atoi(args[0]) : EXIT_SUCCESS;

	exit(status);
}

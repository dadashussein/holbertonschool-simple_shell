#include "shell.h"
#define MAX_INPUT_SIZE 1024
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	while (1)
	{
		command = read_command();
		simple_shell(command);
		free(command);
	}

	return (0);
}


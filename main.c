#include "shell.h"
/**
 * main - Simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;
	char *non_space_ptr;

	while (1)
	{
		command = read_command();

		if (command == NULL)
			break;

		non_space_ptr = command;
		while (*non_space_ptr == ' ')
		{
			non_space_ptr++;
		}

		if (*non_space_ptr != '\0')
		{
			simple_shell(non_space_ptr);
		}

		free(command);
	}

	return (0);
}


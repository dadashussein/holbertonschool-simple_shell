#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/**
 * struct builtin_s - A builtin command.
 * @name: The name of the builtin command.
 * @func: A pointer to a function implementing the builtin command.
 */
typedef struct builtin_s
{
	char *name;
	int (*func)(char **args);
} builtin_t;

char *read_command(void);
char **parse_command(char *line);
void execute_command(char **args);
int exit_builtin(char **args);

#endif

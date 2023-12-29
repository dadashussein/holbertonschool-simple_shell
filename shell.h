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

char *read_command(void);
char **parse_command(char *line);
int execute_command(char **args);
char *find_command_in_path(char *path, char *command);

#endif

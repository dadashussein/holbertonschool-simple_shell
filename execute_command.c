#include "shell.h"

#define UNUSED(x) (void)(x)

/**
 * execute_command_path - Execute a command with a given path.
 *
 * @args: A pointer to a null-terminated array of strings.
 * @path: A pointer to a string containing the path.
 *
 * Return: Nothing.
 */
void execute_command_path(char **args, char *path)
{
    /* ... (unchanged code) */

    /* If the loop completes, the command was not found in any path */
    fprintf(stderr, "Command not found: %s\n", args[0]);
    exit(EXIT_FAILURE);

    UNUSED(path);  /* Suppress unused parameter warning */
}

/**
 * print_environment - Print the current environment variables.
 *
 * Return: Nothing.
 */
void print_environment(void)
{
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}

/**
 * execute_command - Execute a command.
 *
 * @args: A pointer to a null-terminated array of strings.
 *
 * Return: Nothing.
 */
void execute_command(char **args)
{
    pid_t child_pid;
    int status;
    char *path;

    /* Check if the command is the built-in "exit" */
    if (strcmp(args[0], "exit") == 0)
    {
        /* Exit the shell if "exit" is entered */
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        /* If the command is "env", print the environment */
        print_environment();
        return;
    }

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        if (strchr(args[0], '/') != NULL)
        {
            /* If the command includes a '/', use execve directly */
            if (execve(args[0], args, NULL) == -1)
            {
                perror("Error:");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            /* If the command doesn't include a '/', search in PATH */
            path = getenv("PATH");
            execute_command_path(args, path);
        }
    }
    else
    {
        /* In the parent process, wait for the child */
        if (waitpid(child_pid, &status, 0) == -1)
        {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
}

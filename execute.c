#include "shell.h"

/**
 * execute_command - Forks a process and executes the command
 * @args: Array of strings containing the command and its arguments
 *
 * If `execvp` fails, it prints an error message.
 */
void execute_command(char **args)
{
    pid_t pid;

    pid = fork();  /* Create a new process */
    if (pid == -1)
    {
        perror("Error:");
        return;
    }

    if (pid == 0)  /* Child process */
    {
        if (execvp(args[0], args) == -1)  /* Execute the command */
        {
            perror(args[0]);  /* Print error if command fails */
        }
        exit(EXIT_FAILURE);  /* Exit child process */
    }
    else  /* Parent process */
    {
        wait(NULL);  /* Wait for the child process to finish */
    }
}


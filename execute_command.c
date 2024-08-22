#include "shell.h"

/**
 * execute_command - Forks a process and executes the command
 * @args: Array of strings containing the command and its arguments
 *
 * If `execve` fails, it prints an error message.
 */
void execute_command(char **args)
{
    char *cmd_path;
    pid_t pid;

    cmd_path = find_command_path(args[0]); // Find the command path
    if (!cmd_path)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

    pid = fork();  // Create a new process
    if (pid == -1)
    {
        perror("Error:");
        free(cmd_path);
        return;
    }

    if (pid == 0)  /* Child process */
    {
        if (execve(cmd_path, args, NULL) == -1)  // Execute the command
        {
            perror(args[0]);  // Print error if command fails
        }
        free(cmd_path);
        exit(EXIT_FAILURE);  // Exit child process
    }
    else  /* Parent process */
    {
        wait(NULL);
        free(cmd_path);
    }
}


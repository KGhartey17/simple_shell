#include "shell.h"

void execute_command(char **args)
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("Error:");
        return;
    }

    if (pid == 0)  /* Child process */
    {
        if (execvp(args[0], args) == -1)
        {
            perror(args[0]);
        }
        exit(EXIT_FAILURE);
    }
    else  /* Parent process */
    {
        wait(NULL);
    }
}


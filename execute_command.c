#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * execute_command - Executes a command with arguments.
 * @args: Array of strings representing the command and its arguments.
 */
void execute_command(char **args) {
    pid_t pid;
    char *full_path;

    /* Handle empty commands */
    if (args[0] == NULL || args[0][0] == '\0') {
        return; /* Simply return if no command is provided */
    }

    /* Handle built-in 'exit' command */
    if (args[0] != NULL && strcmp(args[0], "exit") == 0) {
        exit(EXIT_SUCCESS);
    }

    /* Resolve the full path of the command */
    if (args[0][0] == '.' || args[0][0] == '/') {
        full_path = strdup(args[0]); /* Use the relative or absolute path directly */
    } else {
        full_path = find_command_path(args[0]); /* Find the command in PATH */
    }

    if (full_path == NULL) {
        /* Command not found in PATH or invalid path */
        fprintf(stderr, "%s: No such file or directory\n", args[0]);
        exit(EXIT_FAILURE);
    }

    pid = fork(); /* Create a new process */
    if (pid == -1) {
        /* Fork failed */
        perror("fork");
        free(full_path);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { /* Child process */
        printf("Executing command: %s\n", full_path);
        execve(full_path, args, NULL); /* Execute the command */
        /* If execve returns, there was an error */
        perror("execve");
        free(full_path);
        exit(EXIT_FAILURE);
    } else { /* Parent process */
        int status;
        waitpid(pid, &status, 0); /* Wait for child process to finish */
        free(full_path);
    }
}


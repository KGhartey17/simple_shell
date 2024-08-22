#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Maximum size for input buffer */
#define MAX_INPUT 1024
/* Maximum number of arguments per command */
#define MAX_ARGS 64

/**
 * parse_input - Splits input string into tokens (command and arguments)
 * @input: The input string from the user
 * @args: Array of strings to hold parsed command and arguments
 */
void parse_input(char *input, char **args);

/**
 * execute_command - Forks a process to execute the command
 * @args: Array of strings containing the command and its arguments
 */
void execute_command(char **args);

#endif /* SHELL_H */


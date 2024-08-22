/* shell.h */
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

/**
 * find_command_path - Searches for the command in directories listed in PATH
 * @cmd: Command to find
 * 
 * Return: Full path to the command if found, NULL otherwise
 */
char *find_command_path(const char *cmd);

/**
 * print_env - Prints the current environment variables
 */
void print_env(void);

#endif /* SHELL_H */


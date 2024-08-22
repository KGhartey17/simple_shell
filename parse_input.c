#include "shell.h"

/**
 * parse_input - Splits input string into tokens (command and arguments)
 * @input: The input string from the user
 * @args: Array of strings to hold parsed command and arguments
 */
void parse_input(char *input, char **args)
{
    char *token;
    int i = 0;

    token = strtok(input, " \t\n"); /* Tokenize the input string */
    while (token != NULL && i < MAX_ARGS - 1)
    {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL; /* Null-terminate the argument array */
}


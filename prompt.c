#include "shell.h"

/**
 * read_line - Reads a line of input from stdin
 *
 * Return: A pointer to the input line
 */
char *read_line(void)
{
    char *line = NULL;  /* Pointer to hold the input line */
    size_t bufsize = 0;

    printf("#cisfun$ ");
    getline(&line, &bufsize, stdin);  /* Read the line of input */

    return line;
}

/**
 * split_line - Splits the input line into tokens
 * @line: The input line to split
 *
 * Return: An array of tokens
 */
char **split_line(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    token = strtok(line, " \t\r\n\a");  /* Split the line into tokens */
    while (token != NULL) {
        tokens[position] = token;
        position++;

        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[position] = NULL;  /* NULL-terminate the array of tokens */
    return tokens;
}


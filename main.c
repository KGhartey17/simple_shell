#include "shell.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1)
    {
        printf("($) ");
        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';  /* Remove newline */

        parse_input(input, args);  /* Parse the input into command and arguments */
        if (args[0] != NULL)        /* Skip empty commands */
            execute_command(args);  /* Execute the command with arguments */
    }

    return (0);
}


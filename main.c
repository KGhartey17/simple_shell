#include "shell.h"

/**
<<<<<<< HEAD
 * main - Entry point for the shell program
 *
 * Return: Always 0 (Success)
 */
=======
 * main - Entry point
 *
 * Return: Always 0, Success.
 */

>>>>>>> 95a2a9691d24b83f44b9533ec894d3c4aec04d21
int main(void)
{
	char input[MAX_INPUT];
	char *args[MAX_ARGS];

<<<<<<< HEAD
    while (1)
    {
        printf("($) ");
        if (fgets(input, MAX_INPUT, stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';  /* Remove newline */

        parse_input(input, args);  /* Parse the input into command and arguments */
        if (args[0] != NULL)        /* Skip empty commands */
            execute_command(args);  /* Execute the command with arguments */
    }
=======
	while (1)
	{
	printf("$ ");

	if (fgets(input, sizeof(input), stdin) == NULL)
		break;

	input[strcspn(input, "\n")] = '\0';  /* Remove newline */

	parse_input(input, args);  /* Parse the input into command and arguments */

	if (args[0] == NULL)  /* Skip empty command */
		continue;

	execute_command(args);  /* Execute the command */
	}
>>>>>>> 95a2a9691d24b83f44b9533ec894d3c4aec04d21

	return (0);
}


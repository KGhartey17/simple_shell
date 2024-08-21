#include "shell.h"

int main(void)
{
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1)
    {
        printf("$ ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';  // Remove newline

        parse_input(input, args);  // Parse the input into command and arguments

        if (args[0] == NULL)  // Skip empty command
            continue;

        execute_command(args);  // Execute the command
    }

    return 0;
}


#include "shell.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1)
    {
        printf("#cisfun$ ");
        nread = getline(&line, &len, stdin);

        if (nread == -1)  /* Handle Ctrl+D */
        {
            free(line);
            exit(EXIT_SUCCESS);
        }

        /* Remove newline character */
        if (line[nread - 1] == '\n')
            line[nread - 1] = '\0';

        if (line[0] != '\0')  /* Ignore empty input */
        {
            execute_command(line);
        }
    }

    free(line);
    return (0);
}


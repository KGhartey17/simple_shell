#include "shell.h"

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
    extern char **environ;
    char **env = environ; /* Pointer to environment variables */

    while (*env != NULL)
    {
        printf("%s\n", *env); /* Print each environment variable */
        env++;
    }
}


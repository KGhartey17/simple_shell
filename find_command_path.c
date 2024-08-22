#include "shell.h"

/**
 * find_command_path - Searches for the command in directories listed in PATH
 * @cmd: Command to find
 * 
 * Return: Full path to the command if found, NULL otherwise
 */
char *find_command_path(const char *cmd)
{
    char *path = getenv("PATH"); // Get PATH environment variable
    if (!path)
        return NULL;

    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    while (dir)
    {
        char full_path[MAX_INPUT];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return strdup(full_path); // Command found, return the full path
        }

        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL; // Command not found
}


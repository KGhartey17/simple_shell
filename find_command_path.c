#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 1024

/**
 * find_command_path - Finds the full path of a command
 * @cmd: The command to find
 * 
 * Return: The full path of the command if found, NULL otherwise
 */
char *find_command_path(const char *cmd) {
    char *path;
    char path_copy[MAX_PATH];
    char *token;
    struct stat st;
    char full_path[MAX_PATH];

    path = getenv("PATH");
    if (path == NULL) {
        perror("getenv");
        return NULL;
    }

    snprintf(path_copy, MAX_PATH, "%s", path);

    token = strtok(path_copy, ":");
    while (token != NULL) {
        snprintf(full_path, MAX_PATH, "%s/%s", token, cmd);
        
        /* Ensure there's only one '/' between the directory and the command */
        if (full_path[strlen(full_path) - 1] == '/') {
            full_path[strlen(full_path) - 1] = '\0';
        }

        printf("Checking: %s\n", full_path);

        if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR)) {
            printf("Found command at: %s\n", full_path);
            return strdup(full_path);
        }

        token = strtok(NULL, ":");
    }

    printf("Command not found in PATH\n");
    return NULL;
}


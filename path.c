#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *find_command_in_path(char *command) {
    struct stat st;
    char *path = getenv("PATH");
    char *dir = strtok(path, ":");
    char *cmd_path = NULL;

    while (dir != NULL) {
        cmd_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!cmd_path) {
            perror("malloc");
            return NULL;
        }
        sprintf(cmd_path, "%s/%s", dir, command);
        if (stat(cmd_path, &st) == 0) {
            return cmd_path;
        }
        free(cmd_path);
        dir = strtok(NULL, ":");
    }
    return NULL;
}


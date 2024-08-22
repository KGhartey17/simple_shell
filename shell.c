#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

void parse_input(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, " \n");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;
}


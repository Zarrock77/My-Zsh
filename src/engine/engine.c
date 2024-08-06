#include "utils.h"
#include "engine.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_prompt(void)
{
    printf("$ ");
}

static int read_input(char *line)
{
    display_prompt();
    if (fgets(line, BUFFER_SIZE, stdin) == NULL) {
        return feof(stdin) ? -1 : 1;
    }
    line[strcspn(line, "\n")] = '\0';
    return 0;
}

void engine(void)
{
    char line[BUFFER_SIZE];
    int status = read_input(line);

    if (status == -1) {
        exit(EXIT_FAILURE);
    } else if (status == 1) {
        return;
    }
    printf("You entered: %s\n", line);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/parser.h"
#include "include/process.h"
#include "include/builtin.h"

int main()
{
    char *line;
    char **tokens;

    printf("=====================================\n");
    printf("ShellForge Version 5.0\n");
    printf("=====================================\n");

    while (1)
    {
        printf("myshell> ");

        line = malloc(1024 * sizeof(char));

        if (line == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        if (fgets(line, 1024, stdin) == NULL)
        {
            free(line);
            break;
        }

        if (strcmp(line, "exit\n") == 0 || strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        tokens = parse_line(line);

        if (tokens != NULL && tokens[0] != NULL)
        {
            if (execute_builtin(tokens) == 0)
            {
                execute(tokens);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}


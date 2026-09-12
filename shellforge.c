#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/parser.h"

int main()
{
    char *line;
    char **tokens;
    int i;

    printf("=====================================\n");
    printf("ShellForge Version 3.0\n");
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

        printf("\nParsed Tokens\n");

        for (i = 0; tokens[i] != NULL; i++)
        {
            printf("argv[%d] = %s\n", i, tokens[i]);
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}


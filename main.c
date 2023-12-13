#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "main.h"

int main(int argc, char **argv)
{
    int i = 0;
    char **tok = NULL;
    char *buffer = NULL;
    size_t size;
    ssize_t flag;

    FILE *file = fopen(argv[1], "r");
    (void) argc;

    if (file == NULL)
        exit(0);
    while((flag = getline(&buffer, &size, file)) != EOF)
    {
        tok = tokenize(buffer, " \t\n$");
        i = 0;
        while(tok[i] != NULL)
        {
            printf("%s\n", tok[i]);
            i++;
        }
        free_ressources(tok);
    }
    fclose(file);
    free_line(buffer);
    return(0);
}

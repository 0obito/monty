#include "monty.h"

void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t **stack, unsigned int line_number);

/**
 * main - Entry point for the Monty program
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char **tokens;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    char line[500];

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        tokens = tokenize(line, " $\n");

        if (tokens != NULL && tokens[0] != NULL)
        {
            int data = 0;
            if (strcmp(tokens[0], "push") == 0)
            {
                if (tokens[1] != NULL)
                    data = atoi(tokens[1]);
                else
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    return (EXIT_FAILURE);
                }
                push(&stack, line_number, data);
            }
            else if (strcmp(tokens[0], "pall") == 0)
            {
                pall(&stack, line_number);
            }
            else
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
                return (EXIT_FAILURE);
            }

            free(tokens);
        }
    }

    fclose(file);
    /*free(line);*/
    return (EXIT_SUCCESS);
}

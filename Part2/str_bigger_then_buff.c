#include "prog.h"

char    *str_bigger_then_buff(FILE *file, char *input)
{
    char    *output;
    char    *current;
    char    *ptr;

    current = malloc(1);
    if (current == 0)
        return (0);
    *current = '\0';
    do
    {
        output = strjoin(current, input);
        if (output == 0)
        {
            free(current);
            printf("Malloc Error!\n");
            return (0);
        }
        free(current);
        current = output;
    } while ((ptr = fgets(input, BUFF_SIZE, file)) != NULL && *(input + strlen(input) - 1) != '\n');
    if (ptr != 0)
    {
        if ((output = strjoin(current, input)) == 0)
        {
            free(current);
            return (0);
        }
        free(current);
    }
    return (output);
}
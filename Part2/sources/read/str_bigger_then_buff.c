#include "../../headers/prog.h"

char    *str_bigger_then_buff(FILE *file, char *input)
{
    char    *output; // full version of str
    char    *current; // sequence of symbols, that we alrdy read
    char    *ptr; // check what "fgets" return

    current = malloc(1);
    if (current == 0)
        return (0);
    *current = '\0';
    do // just join current line and characters's sequence recieved fro buffer (while we dont recieve '\n')
    {
        output = strjoin(current, input);
        if (output == 0)
        {
            free(current);
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
#include "prog.h"

int read_file(t_list **begin, char *file_name)
{
    FILE    *file;
    char    input[BUFF_SIZE];
    char    *output;

    if ((file = fopen(file_name, "r")) == NULL)
        return (1);
    while (fgets(input, BUFF_SIZE, file))
    {
        if ((strlen(input) == BUFF_SIZE - 1 && input[BUFF_SIZE - 2] != '\n'))
            output = str_bigger_then_buff(file, input);
        else
            output = strdup(input);
        if (output == 0)
            return (1);
        begin = list_add_back(begin, output);
        if (begin == 0)
            return (1);
    }
    fclose(file);
    return (0);
}
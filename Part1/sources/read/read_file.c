#include "../../headers/prog.h"

int read_file(t_list **begin, char *file_name)
{
    FILE    *file;
    char    input[BUFF_SIZE]; // here we store some symbols from file
    char    *output; // store full line
    int     num; // number of current str

    num = 1;
    if ((file = fopen(file_name, "r")) == NULL)
        return (1);
    while (fgets(input, BUFF_SIZE, file)) // while we read sth from file, make following instructions. (get current line)
    {
        if ((strlen(input) == BUFF_SIZE - 1 && input[BUFF_SIZE - 2] != '\n'))
            output = str_bigger_then_buff(file, input); // if our buff cant store current file's string
        else
            output = strdup(input); // just duplicate line from file if buff can store it
        if (output == 0)
        {
            printf("Malloc error!\n");
            exit(0);
        }
        begin = list_add_back(begin, output, num); // add current line in list
        if (begin == 0)
        {
            printf("Malloc error!\n");
            exit(0);
        }
        num++;
    }
    fclose(file);
    return (0);
}
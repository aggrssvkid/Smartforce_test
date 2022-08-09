#include "../../headers/prog.h"

char    *find_substr(char *str, char *substr)
{
    if (str == 0 || substr == 0)
        return (0);
    
    char    *hold_pos; // rememmber the position of first match str and substr
    char    *start;

    start = substr;
    while (*str != '\n' && *str != '\0')
    {
        if (*str == *substr)
        {
            hold_pos = str;
            while (*str == *substr && *substr != '\0')
            {
                str++;
                substr++;
            }
            if (*substr == '\0')
                return (hold_pos);
            substr = start;
            str = hold_pos;
        }
        str++;
    }
    return (0);
}
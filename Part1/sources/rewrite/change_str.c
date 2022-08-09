#include "../../headers/prog.h"

static char *get_end(char *substr, int len_substr)
{
    char    *end;
    char    *begin;

    begin = substr +len_substr;
    end = strdup(begin);
    if (end == 0)
        return (0);
    return (end);
}

static char *get_begin(char *str, char *end)
{
    char    tmp;
    char    *begin;

    tmp = *end;
    *end = '\0';
    begin = strdup(str);
    *end = tmp;
    if (begin == 0)
        return (0);
    return (begin);
}

char    *change_str(char *str, char *substr, int len_substr, char *change)
{
    char    *begin; // sequence of str symbols, that we  want to store from the start of str
    char    *end; // sequence of str symbols, that we  want to store between "subsrt's end" and "str's end"
    char    *new; // pointer that indicates on changed line

    begin = get_begin(str, substr);
    if (begin == 0)
        return (0);
    end = get_end(substr, len_substr);
    if (end == 0)
    {
        free(begin);
        return (0);
    }
    new = strjoin(begin, change);
    if (new == 0)
    {
        free(begin);
        free(end);
        return (0);
    }
    free(begin);
    begin = new;
    new = strjoin(new, end);
    if (new == 0)
    {
        free(begin);
        free(end);
        return (0);
    }
    free(begin);
    free(end);
    return (new);
}
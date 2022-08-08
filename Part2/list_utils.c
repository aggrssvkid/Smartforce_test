#include "prog.h"

void    lst_clear(t_list **begin)
{
    t_list  *tmp;

    if (*begin == 0)
        return ;
    while (*begin != 0)
    {
        tmp = (*begin)->next;
        free((*begin)->str);
        free(*begin);
        *begin = tmp;
    }
}

t_list  **list_add_back(t_list **begin, char *input)
{
    t_list  *new_list;
    t_list  *runner;

    if (*begin == 0)
    {
        *begin = list_init(input);
        if (*begin == 0)
            return (0);
        return (begin);
    }
    new_list = malloc(sizeof(t_list));
    if (new_list == 0)
    {
        lst_clear(begin);
        return (0);
    }
    runner = *begin;
    while (runner->next != 0)
        runner = runner->next;
    runner->next = new_list;
    runner = runner->next;
    runner->next = 0;
    runner->str = input;
    return (begin);
}

t_list  *list_init(char *input)
{
    t_list  *new_list;

    new_list = malloc(sizeof(t_list));
    if (new_list == 0)
        return (0);
    new_list->next = 0;
    new_list->str = input;
    return (new_list);
}
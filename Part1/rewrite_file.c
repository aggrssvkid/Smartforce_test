#include "prog.h"

int rewrite_file(t_list **begin, char *fullname, char **argv)
{
    t_list  *runner;
    FILE    *file;
    char    *new;
    char    *find;
    char    *helper;

    if ((file = fopen(fullname, "w")) == NULL)
        return (2);
    runner = *begin;
     while (runner)
            {
                printf("%s", (runner)->str);
                (runner) = (runner)->next;
            }
    runner = *begin;
    while (runner)
    {
        if (strcmp(runner->str, argv[2]) == 0)
            fputs(argv[3], file);
        else if ((find = find_substr(runner->str, argv[2])) != 0)
        {
            new = runner->str;
            while (find)
            {
                helper = new;
                new = change_str(new, find, strlen(argv[2]), argv[3]);
                printf("New str:%s\n", new);
                if (helper != runner->str)
                    free(helper);
                if (new == 0)
                    return (1);
                find = find_substr(new, argv[2]);
            }
            fputs(new, file);
            free(new);
        }
        else
            fputs(runner->str, file);
        runner = runner->next;
    }
    return (0);
}
#include "../../headers/prog.h"

void    go_rewrite(t_rewrite *rewrite, char **argv)
{
    rewrite->new_str = strdup(rewrite->runner->str);
    if (rewrite->new_str == 0)
    {
        printf("Malloc error!");
        exit(0);
    }
    rewrite->keep_it = rewrite->new_str + (rewrite->find - rewrite->runner->str); // the "keep_it" ptr indicate on end of sequence. We must store evrything befre it.
    rewrite->len_difference = strlen(argv[3]) - strlen(argv[2]); // len_difference - +offset with evry iteration
    rewrite->offset = 0; // offset - offset of "new_str" with regard to "str"
    while (rewrite->find) // while we find substr in "str", change str
    {
        rewrite->offset += rewrite->len_difference;
        rewrite->helper = rewrite->new_str;
        rewrite->new_str = change_str(rewrite->new_str, rewrite->keep_it, strlen(argv[2]), argv[3]);
        free(rewrite->helper);
        if (rewrite->new_str == 0)
        {
            printf("Malloc error!");
            exit(0);
        }
        rewrite->find = find_substr(rewrite->find + strlen(argv[2]), argv[2]);
        if (rewrite->find)
            rewrite->keep_it = rewrite->new_str + (rewrite->find - rewrite->runner->str) + rewrite->offset;
    }
    fputs(rewrite->new_str, rewrite->file);
    add_log(rewrite->runner, rewrite->new_str, rewrite->logfile);
    free(rewrite->new_str);
}


int rewrite_file(t_list **begin, char *fullname, char **argv, char *logfilename)
{
    t_rewrite   rewrite;

    if ((rewrite.file = fopen(fullname, "w")) == NULL)
        return (2);
    if ((rewrite.logfile = fopen(logfilename, "w")) == NULL)
    {
        fclose(rewrite.file);
        return (2);
    }
    rewrite.runner = *begin;
    while (rewrite.runner)
    {
        if (strcmp(rewrite.runner->str, argv[2]) == 0)
        {
            fputs(argv[3], rewrite.file);
            add_log(rewrite.runner, argv[3], rewrite.logfile);
        }
        else if ((rewrite.find = find_substr(rewrite.runner->str, argv[2])) != 0)
            go_rewrite(&rewrite, argv);
        else
            fputs(rewrite.runner->str, rewrite.file);
        rewrite.runner = rewrite.runner->next;
    }
    fclose(rewrite.file);
    fclose(rewrite.logfile);
    return (0);
}
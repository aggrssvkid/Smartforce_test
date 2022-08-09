#include "../../headers/prog.h"

void    add_log(t_list *list, char *after, FILE *logfile)
{
    fprintf(logfile, "String number %i\nStart string:%s-->End string:%s", list->num, list->str, after);
}
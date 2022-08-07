#include "prog.h"

char    *get_fullname(char *path, char *name)
{
    char    *fullname;
    char    *help;

    fullname = strjoin(path, "/");
    if (fullname == 0)
        return (0);
    help = fullname;
    fullname = strjoin(fullname, name);
    free(help);
    if (fullname == 0)
        return (0);
    return (fullname);
}
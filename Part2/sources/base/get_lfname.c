#include "../../headers/prog.h"

char    *get_lfname(char *filename)
{
    char    *lfname;

    lfname = strjoin("log:", filename);
    if (lfname == 0)
        return (0);
    return (lfname);
}
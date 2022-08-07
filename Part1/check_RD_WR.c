#include "prog.h"

int check_RD_WR(char *fullname)
{
    if (access(fullname, R_OK))
        return (1);
    if (access(fullname, W_OK))
        return (2);
    return (0);
}
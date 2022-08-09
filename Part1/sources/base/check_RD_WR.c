#include "../../headers/prog.h"

int check_RD_WR(char *fullname)
{
    if (access(fullname, R_OK)) // can we read file?!
        return (1);
    if (access(fullname, W_OK)) // can we write into file
        return (2);
    return (0);
}
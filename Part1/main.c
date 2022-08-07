#include "prog.h"

int main(int argc, char **argv)
{
    
    if (argc != 4)
    {
        printf("args number must be equal 4!\n");
        return (0);
    }

    DIR*            main_dir;

    if ((main_dir = opendir(argv[1])) == NULL)
    {
        printf("Cant open this directory, ERROR!\n");
        return (0);
    }

    DIR*            check;
    struct dirent*  file;
    t_list          *file_str;
    char            *full_fname;

    file_str = 0;
    full_fname = 0;
    while ((file = readdir(main_dir)))
    {
        if ((check = opendir(file->d_name)) != NULL)
        {
            printf("Its directory, not file:%s\n", file->d_name);
            closedir(check);
        }
        else
        {
            full_fname = get_fullname(argv[1], file->d_name);
            if (full_fname == 0)
            {
                printf("Malloc error!\n");
                exit(0);
            }
            if (check_RD_WR(full_fname))
                printf("Cant read this file:%s\n", full_fname);
            else
            {
                if (read_file(&file_str, full_fname))
                    printf("Error in read_file!\n");
                else
                {
                    if(rewrite_file(&file_str, full_fname, argv))
                        printf("Error in rewrite_file!\n");
                }
            }
        }
    }
    exit(0);
}

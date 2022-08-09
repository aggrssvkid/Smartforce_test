#include "../../headers/prog.h"

int main(int argc, char **argv)
{
    
    if (argc != 4)
    {
        printf("args number must be equal 4!\n");
        return (0);
    }

    DIR             *main_dir; // desired folder, that i got as argv[1]

    if ((main_dir = opendir(argv[1])) == NULL) // open the desired folder and check did i do that
    {
        printf("Cant open this directory, ERROR!\n");
        return (0);
    }

    DIR             *check; // its for check for another folders in "main_dir"
    struct dirent   *file; // keep info about current file in "main_dir"
    t_list          *file_str; // list for stroing info contained in the file
    char            *full_fname; // full path/name to file
    char            *logfilename; // logfile will be open with this name

    while ((file = readdir(main_dir)))
    {
        full_fname = get_fullname(argv[1], file->d_name);
        logfilename = 0;
        file_str = 0;
        if (full_fname == 0)
        {
            printf("Malloc error!\n");
            exit(0);
        }
        if ((check = opendir(full_fname)) != NULL) // check current file. Its directory or file?!
        {
            printf("Its directory, not file:%s\n", file->d_name);
            closedir(check);
        }
        else // if its file, move here!
        {
            if (check_RD_WR(full_fname)) // can i write/read file's info
                printf("Cant read/write this file:%s\n", full_fname);
            else
            {
                if (read_file(&file_str, full_fname)) // copy all file's strings in lists. If success go to next else
                    printf("Error in read_file!\n");
                else
                {
                    logfilename = get_lfname(file->d_name);
                    if (logfilename == 0)
                    {
                        printf("Malloc error!\n");
                        exit(0);
                    }
                    if (rewrite_file(&file_str, full_fname, argv, logfilename)) // looking for sequence of characters, that matches with argv[2] and change it on argv[3]
                        printf("Error in rewrite_file!\n");                     
                }
            }
        }
        free(full_fname); // clear allocated memory, during the program
        if (logfilename)
            free(logfilename);
        if (file_str)
            lst_clear(&file_str);
    }
    exit(0);
}

#ifndef PROG_H
#define PROG_H

 #define BUFF_SIZE 11

 #include <stdio.h>
 #include <string.h>
 #include <dirent.h>
 #include <stdlib.h>
 #include <unistd.h>
 
 /*
 Struct for saving file's strings
 */

typedef struct s_list
{
    int             num;
    char           *str;
    struct s_list  *next;
}   t_list;

/*
Struct for "rewrite" function. There is all params needed for it
*/

typedef struct  s_rewrite
{
    t_list  *runner;
    FILE    *file;
    FILE    *logfile;
    char    *new_str;
    char    *find;
    char    *helper;
    char    *keep_it;
    int     len_difference;
    int     offset;
}   t_rewrite;


char	*strjoin(char const *s1, char const *s2); // strings' concatenation
int     rewrite_file(t_list **begin, char *fullname, char **argv, char *logfilename); // write in empty file depending on "argv"
int     read_file(t_list **begin, char *file_name); // write strings in lists. One string = one list.
t_list  *list_init(char *input, int num); // list init
t_list  **list_add_back(t_list **begin, char *input, int num); // add new list in the end of lists
void    lst_clear(t_list **begin); // clear all lists
char    *str_bigger_then_buff(FILE *file, char *input); // if we cant put string from file in our buff, we need to use this func
char    *get_fullname(char *path, char *name); // get full path to file
char    *find_substr(char *str, char *substr); // find first substring in big string
char    *change_str(char *str, char *substr, int len_substr, char *change); // change "substr" in base "str" on another string
int     check_RD_WR(char *fullname); // can we read/write info into file?!
void    add_log(t_list *list, char *after, FILE *logfile);// write info about changes input file's
char    *get_lfname(char *filename); // get logfile name depending on input file name

#endif
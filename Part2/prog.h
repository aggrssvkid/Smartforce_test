#ifndef PROG_H
#define PROG_H

 #define BUFF_SIZE 11

 #include <stdio.h>
 #include <string.h>
 #include <dirent.h>
 #include <stdlib.h>
 #include <unistd.h>

typedef struct s_list
{
    char           *str;
    struct s_list  *next;
}   t_list;

char	*strjoin(char const *s1, char const *s2);
int     rewrite_file(t_list **begin, char *fullname, char **argv);
int     read_file(t_list **begin, char *file_name);
t_list  *list_init(char *input);
t_list  **list_add_back(t_list **begin, char *input);
void    lst_clear(t_list **begin);
char    *str_bigger_then_buff(FILE *file, char *input);
char    *get_fullname(char *path, char *name);
char    *find_substr(char *str, char *substr);
char    *change_str(char *str, char *substr, int len_substr, char *change);
int     check_RD_WR(char *fullname);

#endif
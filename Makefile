SRCS = $(wildcard sources/*/*.c)

OBJS = $(SRCS:%.c=%.o)

HEADER = headers/prog.h

NAME = Prog

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = gcc

.PHONY :	all clean fclean re

all		:		$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	$(RM) $(OBJS)

fclean	:		clean
	$(RM) $(NAME)

re		:		fclean all
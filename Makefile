NAME = ft_mini_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_mini_ls.c \
	   utils/ft_putstr_fd.c \
	   utils/ft_strlen.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	rm -f $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean $(NAME)

.PHONY	: all clean fclean re

NAME = ft_mini_ls
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -lm -L libft -lft
SRCS = ft_lstsort.c \
	   ft_lstswap.c \
	   ft_mini_ls.c \
	   ft_print_dir.c \
	   ft_readdir.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS) -o $@

clean:
	make clean -C libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	make fclean -C libft
	rm -f $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean $(NAME)

.PHONY	: all clean fclean re
HONY: all clean fclean re

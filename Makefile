NAME =	fillit
SRC =	ft_read.c \
		ft_checker.c \
		ft_strsplit.c \
		ft_lists.c \
		ft_strsplit2.c \
		ft_long.c \
		ft_algorithm.c \
		ft_find.c \
		ft_printarr.c \
		ft_writemap.c \
		main.c

OBJ =	$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $^

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

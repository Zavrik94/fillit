NAME =	fillit
SRC_D = src/
SRC =	$(SRC_D)ft_read.c \
		$(SRC_D)ft_checker.c \
		$(SRC_D)ft_splitinput.c \
		$(SRC_D)ft_lists.c \
		$(SRC_D)ft_splittetra.c \
		$(SRC_D)ft_counttetramin.c \
		$(SRC_D)ft_algorithm.c \
		$(SRC_D)ft_find.c \
		$(SRC_D)ft_printarr.c \
		$(SRC_D)ft_writemap.c \
		fillit.c
LIB_D = libft/
LIB = $(LIB_D)libft.a
OBJ =	$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_D)
	gcc $(CFLAGS) -o $(NAME) $^ $(LIB) -I $(LIB_D)

%.o: %.c
	gcc $(CFLAGS) -o $@ -c $<

clean:
	make clean -C $(LIB_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_D)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

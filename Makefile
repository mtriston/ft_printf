NAME = libftprintf.a

LIB = libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(NAME) has been compiled

$(LIB):
	@make -f ./libft/Makefile

%.c: %.o
	gcc $(CFLAGS) -c $<

clean:
	@rm -f $(OBJ)
	@echo All object files have been removed

fclean: clean
	@rm -f $(NAME)

re: fclean all

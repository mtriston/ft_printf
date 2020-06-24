COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = [OK]
ERROR_STRING = [ERROR]
WARN_STRING  = [WARNING]
COM_STRING   = Compiling

NAME = libftprintf.a

HEAD = ./ft_printf.h

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft

FLAGS = -Wall -Werror -Wextra

CC = clang

SRC = ft_printf.c           \
	  check_modifications.c \
	  apply_flags.c         \
	  apply_width.c         \
	  print_number.c        \
	  print_string.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make bonus -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(OK_COLOR) $(OK_STRING) $(OBJ_COLOR) $(NAME) $(NO_COLOR)"
.c.o: $(HEAD)
	@$(CC) $(FLAGS) -c $<
	@echo "$(COM_COLOR) $(COM_STRING) $(OBJ_COLOR) $(@) $(NO_COLOR)"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(WARN_COLOR) $(NAME) has been removed $(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re

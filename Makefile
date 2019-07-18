
NAME = app

SRC = main.c

LIB = ../libft/libft.a

BUILD = gcc -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME): $(LIB)
	@$(BUILD) $(NAME) $(SRC) $(LIB)
	@echo "app created"

$(LIB):
	@make -C ../libft

clean:
	@rm -rf $(NAME)
	@echo "app deleted"

fclean: clean

re: fclean all

lib:
	@make re -C ../libft

.PHONY: clean fclean all re

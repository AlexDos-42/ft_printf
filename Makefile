NAME = libftprint.a

SRCS =		ft_printf.c \
  		application.c \
		ft_parsing.c \
		ft_utile.c \
		main.c \

HEADERS	= -I./include/

FLAGS = -Wall -Wextra -Werror -g

OBJ	= $(SRCS:.c=.o)

all: ${NAME}

$(NAME):
	make -C ./libft/
	gcc -L./libft -lft $(FLAGS) -o $(NAME) $(SRCS) $(HEADERS)

clean:
	make clean -C ./libft/
	rm -rf $(SRCS:.c=.o)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

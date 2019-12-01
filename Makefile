NAME = libftprint.a

SRCS =		ft_printf.c \
  		application.c \
		ft_parsing.c \
		ft_utile.c \
		
HEADERS	= -I./include/

FLAGS = -Wall -Wextra -Werror -g3

OBJ	= $(SRC:.c=.o)

all: ${NAME}

$(NAME):
	make -C ./libft/
	gcc  -L./libft -lft $(FLAGS) -o $(NAME) $(SRC) $(HEADERS)

clean:
  make clean -C ./libft/
  rm -rf $(SRCS:.c=.o)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

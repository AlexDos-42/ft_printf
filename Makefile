NAME = libftprintf.a

SRCS =		ft_printf.c \
  		application.c \
		ft_parsing.c \
		ft_utile.c \

SRCSLIB = *.c \

HEADERS	= -I ./include/

FLAGS = -Wall -Wextra -Werror

OBJ	= $(SRCS:.c=.o)

all: ${NAME}

$(NAME):
	@echo "Compilation de ft_printf..."
	@(make -C ./libft/)
	@(gcc $(FLAGS) -c $(SRCS) -I .)
	@(ar rc $(NAME) $(OBJ) ./libft/*.o)
	@echo "Compilation terminée"

clean:
	@echo "Clean"
	@(make clean -C ./libft/)
	@rm -rf $(SRCS:.c=.o)

fclean:	clean
	@echo "Fclean"
	@(make fclean -C ./libft/)
	@(rm -rf $(NAME))

re:	fclean all

.PHONY:	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alesanto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 14:42:29 by alesanto          #+#    #+#              #
#    Updated: 2019/12/16 17:51:19 by alesanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =		ft_printf.c \
  		application.c \
		ft_parsing.c \
		ft_utile.c 

PATHSRCS = srcs

PATHTMP = tmp

HEADERS	= ./include

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(PATHSRCS)/,$(SRC))
OBJS = $(addprefix $(PATHTMP)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilation de ft_printf..."
	@(make -C libft/)
	@(cp libft/libft.a ./$(NAME))
	@(ar rc $(NAME) $(OBJS))
	@(ranlib $(NAME))
	@echo "Compilation terminée"

$(PATHTMP)/%.o: $(PATHSRCS)/%.c
	@(mkdir -p tmp)
	@(gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<)

clean:
	@echo "Clean"
	@(make clean -C ./libft/)
	@(rm -rf $(PATHTMP))
	@(rm -rf $(SRCS:.c=.o))

fclean:	clean
	@echo "Fclean"
	@(make fclean -C ./libft/)
	@(rm -rf $(NAME))

re:	fclean all

.PHONY:	all clean fclean re

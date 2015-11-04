#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 11:44:10 by klescaud          #+#    #+#              #
#    Updated: 2015/11/04 12:30:40 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fdf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LFLAGS	= -L./libft -lft -L/usr/X11/lib -lXext -lX11 -lmlx

SRC		= 	./sources/graphics.c \
			./sources/get_line.c \
			./sources/hooks.c \
			./sources/helper.c \
			./sources/init.c \
			./sources/main.c

INC		= -I./includes -I./libft/includes

OBJ		= graphics.o get_line.o hooks.o helper.o init.o main.o

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(SRC) $(CFLAGS) $(INC)
	@echo "Linking binary."
	@$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	@echo "Deleting obj files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting fdf."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
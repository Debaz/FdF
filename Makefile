#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 11:44:10 by klescaud          #+#    #+#              #
#    Updated: 2015/11/04 11:48:03 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		Fdf

SRC=		./sources/main.c \
			./sources/graphics.c \
			./sources/parser.c \
			./sources/functions.c

OBJ=		./main.o \
			./graphics.o \
			./parser.o \
			./functions.o

CC=			gcc

FLAGS=		-Wall -Wextra -Werror

LD_FLAGS=	-lmlx -L/usr/X11/lib -framework OpenGL -framework AppKit

INC_FLAGS=  -I/opt/X11/include/X11 -I./includes

export CC=	gcc

export CFLAGS= -Wall -Wextra -Werror

all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(CC) -o $(NAME) $(MLX) $(OBJ) $(LD_FLAGS)
				@echo "$(NAME) is done !"

%.o : 			%.c includes/fdf.h
				@$(CC) -c $< -o $@ $(INC_FLAGS) $(FLAGS)

clean:
				@rm -f $(OBJ)
				@echo "objs are cleaned!"

fclean: 		clean
				@rm -rf $(NAME)
				@echo "$(NAME) is cleaned !"

re:				fclean all

.PHONY :        all fclean re
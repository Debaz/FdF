#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 11:44:10 by klescaud          #+#    #+#              #
#    Updated: 2015/11/06 10:16:48 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= 	fdf

CFLAGS	= 	-Wall -Wextra -Werror

LFLAGS	= 	-L./libft -lft -lmlx -framework OpenGL -framework AppKit

SRCS	= 	./sources/fdf_cal_matrice.c \
			./sources/fdf_draw.c \
			./sources/fdf_error.c \
			./sources/fdf_helper.c \
			./sources/fdf_hook.c \
			./sources/fdf_matrice.c \
			./sources/parse_arg.c \
		 	./sources/main.c

INC		= 	-I./includes -I./libft/includes

OBJ		= 	fdf_cal_matrice.o \
			fdf_draw.o \
			fdf_error.o \
			fdf_helper.o \
			fdf_hook.o \
			fdf_matrice.o \
			parse_arg.o \
			main.o

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -c $(SRCS) $(INC) $(CFLAGS)
	@gcc -o $(NAME) $(OBJ) $(INC) $(CFLAGS) $(LFLAGS)

clean:
	@echo "Deleting obj files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting fdf."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
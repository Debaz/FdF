#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 11:44:10 by klescaud          #+#    #+#              #
#    Updated: 2015/11/05 13:14:37 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= 	fdf

CFLAGS	= 	-Wall -Wextra -Werror

LFLAGS	= 	-L./libft -lft -lmlx -framework OpenGL -framework AppKit

SRCS	= 	./sources/main.c \
			./sources/draw.c \
			./sources/math.c \
			./sources/event.c

INC		= 	-I./includes -I./libft/includes

OBJ		= 	main.o draw.o math.o event.o

all: $(NAME)

$(NAME):
	@make -C ./libft
	@echo "Linking binary."
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
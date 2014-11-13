#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 12:27:54 by klescaud          #+#    #+#              #
#    Updated: 2014/11/13 16:26:43 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		FdF

SOURCES =	./source/main.c				\
			./source/graphics.c

LIBPATH =	./source/libft/

INCLUDES =	-I./includes/ -I./source/libft/includes/

CFLAGS =	-Wall -Wextra -Werror

CLIB =		-L./source/libft/ -L/usr/X11/lib -lft -lmlx -lXext -lX11

all: $(NAME)

$(NAME): libft
	@echo "Compilation de FdF ..."
	@gcc -o $(NAME) $(SOURCES) $(INCLUDES) $(CLIB) $(CFLAGS)
	@echo "Succes."

libft:
	@echo "Compilation de la libft ..."
	@make -C $(LIBPATH)
	@echo "Supression des fichiers temporaires ..."
	@make -C $(LIBPATH) clean
	@echo "Succes."

libftclean:
	@echo "Supression de la libft ..."
	@make -C $(LIBPATH) fclean
	@echo "Succes."

clean: libftclean

fclean: clean
	@echo "Supression de l'executable ..."
	@rm $(NAME)
	@echo "Succes."

re: fclean all
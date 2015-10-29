#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Debaz <klescaud@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/28 11:15:25 by Debaz             #+#    #+#              #
#    Updated: 2015/10/29 12:24:11 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRCS = ./sources/main.c

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I./libft/includes/ -I./includes/

LIBPATH = ./libft/

all: $(NAME)

$(NAME):
	@echo "Compilation du projet ..."
	@make -C $(LIBPATH)
	@gcc -o $(NAME) $(SRCS) $(INCLUDES) $(CFLAGS)
	@echo "Done !"

clean:
	@make -C $(LIBPATH) fclean
	@echo "Binaires detruits."

fclean: clean
	@rm $(NAME)
	@echo "Projet detruit."

re: fclean all
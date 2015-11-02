#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Debaz <klescaud@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/28 11:15:25 by Debaz             #+#    #+#              #
#    Updated: 2015/10/31 15:50:09 by Debaz            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRCS = 	./sources/main.c \
		./sources/fdf_parse.c

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

INCLUDES = -I./libft/includes/ -I./includes/

LIBPATH = ./libft/

all: $(NAME)

$(NAME):
	@make -C $(LIBPATH)
	@echo "Compilation du projet ..."
	@gcc -o $(NAME) $(SRCS) $(INCLUDES) $(CFLAGS) -L$(LIBPATH) -lft
	@echo "Done !"

clean:
	@make -C $(LIBPATH) fclean
	@echo "Binaires detruits."

fclean: clean
	@rm $(NAME)
	@echo "Projet detruit."

re: fclean all
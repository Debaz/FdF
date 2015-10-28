#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Debaz <klescaud@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/28 11:15:25 by Debaz             #+#    #+#              #
#    Updated: 2015/10/28 16:33:22 by Debaz            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRCS = ./sources/

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

OBJ =

INCLUDES = ./sources/libft/includes/ ./includes/

LIBPATH = ./sources/libft/

all: $(NAME)

$(NAME):
	@echo "Compilation du projet ..."
	@make -C $(LIBPATH)
	@gcc -o $(NAME) $(SRCS)
	@echo "Done !"

clean:
	@rm $(OBJ)
	@make -C $(LIBPATH) fclean
	@echo "Binaires detruits."

fclean: clean
	@rm $(NAME)
	@echo "Projet detruit."

re: fclean all
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/12 11:13:35 by klescaud          #+#    #+#              #
#    Updated: 2015/11/12 11:17:00 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME= 	fdf

LNAME=	libft

SRC=	fdf_algo.c	fdf_coloor.c	fdf_ligne.c		fdf_algo2.c		main.c	\
		fdf_core.c	fdf_map.c		fdf_algo2b.c	fdf_error.c

OBJ= $(SRC:.c=.o)

CC= 		gcc

FLAGS= 		-Wall -Wextra -Werror

INCLUDES=	libft/libft.a

MLX=		-lmlx -L/usr/X11/lib -framework OpenGL -framework AppKit -Llibft -lft

HELLO_DIR=libft

EXEC=$(HELLO_DIR)/libft.a

export CC=	gcc

export CFLAGS= -Wall -Wextra -Werror

all: 			$(EXEC) $(NAME)

$(EXEC):
				@(cd $(HELLO_DIR) && $(MAKE))

$(NAME): 		$(OBJ)
				@echo "$(NAME) => DONE."

%.o : 			%.c
				@$(CC) $(FLAGS) -o $(NAME) $(SRC) $(MLX) $(INCLUDES)

clean:
				@rm -f $(OBJ)
				@(cd $(HELLO_DIR) && $(MAKE) $@)
				@echo "$(NAME)_objs => CLEANED."

fclean: 		clean
				@rm -rf $(NAME)
				@(cd $(HELLO_DIR) && $(MAKE) $@)
				@echo "$(NAME) => CLEANED."

re:				fclean all

.PHONY :        all fclean re

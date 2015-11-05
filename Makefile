#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <klescaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 11:44:10 by klescaud          #+#    #+#              #
#    Updated: 2015/11/04 13:49:57 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fdf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-missing-noreturn \
			-Wno-padded -Wno-unreachable-code -Wredundant-decls \
			-Wmissing-declarations

LFLAGS	= -L./libft -lft -L/usr/X11/lib -lXext -lX11 -lmlx

SRC_DIR	= ./srcs/

SRC		= drawline.c get_line.c hooks.c helper.c init.c main.c

VPATH	= $(SRC_DIR)

INC		= -I./includes -I./libft/includes

O_DIR	= ./obj

OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@echo "Linking binary."
	@$(CC) -o $(NAME) $^ $(LFLAGS)

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "."
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@

clean:
	@echo "Deleting obj files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting fdf."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
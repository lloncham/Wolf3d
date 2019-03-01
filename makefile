# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 10:08:40 by lloncham          #+#    #+#              #
#    Updated: 2019/02/28 15:21:07 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = src

SRC_NAME = main.c tools.c read.c raycast.c deal_key.c color.c texture.c

OBJ_PATH = obj

CPPFLAGS = include

LDFLAGS = -L./libft
LDLIBS = -lft
MLXFLAGS = -L./minilibx_macos
MLXLIBS = -lmlx

CC = clang

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C libft
		$(MAKE) -C minilibx_macos
		$(CC) -g -fsanitize=address $(LDFLAGS) $(LDLIBS) $^ -o $@ $(MLXFLAGS) $(MLXLIBS) -framework OpenGL -framework AppKit

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) -I $(CPPFLAGS) -o $@ -c $<

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx_macos clean
	rm -rf $(OBJ_PATH) 

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

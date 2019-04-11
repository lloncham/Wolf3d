# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/25 10:08:40 by lloncham          #+#    #+#              #
#    Updated: 2019/04/04 15:13:16 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CC = clang

SRC_PATH = src

SRC_NAME = main.c tools.c read.c raycast.c deal_key.c mini_map.c texture.c init_raycast.c menu.c music.c text_wall_floor.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude

LDFLAGS = -Llibft
LDLIBS = -lft

MLXFLAGS = -Lminilibx_macos
MLXLIBS = -lmlx

CFLAGS = -Werror -Wall -Wextra -g

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
	RED=\033[1;31m
	GREEN=\033[1;32m
.SILENT:

all: $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
		$(MAKE) -C libft
		$(MAKE) -C minilibx_macos
		$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@ -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
		echo "$(GREEN)[✓] Wolf3D"

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx_macos clean
	rm -rf $(OBJ_PATH)
	echo "$(RED)[✓] Clean!"


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	echo "$(RED)[✓] Fclean!"

re: fclean all

.PHONY: all, clean, fclean, re

norme:
	norminette $(SRC)
	norminette include/*.h

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

CC = clang

SRC_PATH = src

SRC_NAME = main.c tools.c read.c raycast.c deal_key.c mini_map.c texture.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude

LDFLAGS = -Llibft
LDLIBS = -lft

MLXFLAGS = -Lminilibx_macos
MLXLIBS = -lmlx

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C libft
		$(MAKE) -C minilibx_macos
		$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@ -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

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

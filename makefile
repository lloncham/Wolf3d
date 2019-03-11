# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 11:42:33 by lloncham          #+#    #+#              #
#    Updated: 2019/03/11 11:46:08 by lloncham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(INDIR)

SRC = src/deal_key.c src/read.c src/init_raycast.c src/main.c    src/raycast.c src/menu.c \
	       src/mini_map.c src/texture.c src/tools.c
OBJECT = $(SRC:.c=.o)

INDIR = Includes

all: $(NAME)

$(NAME) : $(OBJECT)
	    cd libft ; $(MAKE) -f Makefile
		    $(MAKE) -C minilibx_macos
			    $(CC) -g -fsanitize=address -o $(NAME) $(CFLAGS) $(SRC) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean :
	    @cd libft ; $(MAKE) -f Makefile clean


fclean : clean
	    rm -f $(NAME)
		    rm -f $(OBJECT)

re : fclean all

.PHONY: all clean fclean

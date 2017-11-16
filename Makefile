# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 19:02:53 by lbelda            #+#    #+#              #
#    Updated: 2017/11/16 18:52:04 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=srcs/main.c \
	srcs/fdf.c \
	srcs/hooks.c

OBJ=$(SRC:%.c=%.o)
INCLUDES=includes/
HEADER=fdf.h

LFTDIR=libft/
LIBFT=libft.a
FTLK=ft

LMLXDIR=minilibx/
LIBMLX=libmlx.a
MLXLK=mlx
FRAMEWORKS=-framework OpenGL -framework AppKit

NAME=fdf
CC=gcc
CFLAGS=-Wall -Wextra -Werror
MAKE=make

all: $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT) $(LMLXDIR)$(LIBMLX)
	$(CC) -o $(NAME) -I$(LFTDIR) -I$(LMLXDIR) -I$(INCLUDES) -L$(LFTDIR) -l$(FTLK) -L$(LMLXDIR) -l$(MLXLK) $(FRAMEWORKS) $(OBJ)
	echo "FdF ready."

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -I$(LFTDIR) -I$(LMLXDIR) -I$(INCLUDES) -c $^

$(LFTDIR)$(LIBFT):
	$(MAKE) -C $(LFTDIR)

$(LMLXDIR)$(LIBMLX):
	$(MAKE) -C $(LMLXDIR)

clean:
	$(MAKE) -C $(LFTDIR) clean
	rm -rf *.h.gch
	rm -rf *.o

fclean: clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(LMLXDIR) clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

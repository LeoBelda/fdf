# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 19:02:53 by lbelda            #+#    #+#              #
#    Updated: 2017/11/17 20:43:55 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=srcs/main.c \
	srcs/fdf.c \
	srcs/hooks.c \
	srcs/parse_map.c \
	srcs/camera.c \
	srcs/debug.c

OBJ=$(SRC:%.c=%.o)
INCLUDES=includes/
HEADER=fdf.h

LFTDIR=libft/
LIBFT=libft.a
FTLK=ft

LFTMTDIR=libftmath/
LIBFTMT=libftmath.a
FTMTLK=ftmath

LMLXDIR=minilibx/
LIBMLX=libmlx.a
MLXLK=mlx
FRAMEWORKS=-framework OpenGL -framework AppKit

NAME=fdf
CC=gcc
CFLAGS=-Wall -Wextra -Werror
MAKE=make

all: $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT) $(LFTMTDIR)$(LIBFTMT) $(LMLXDIR)$(LIBMLX)
	-@$(CC) -o $(NAME) -I$(LFTDIR) -I$(LFTMTDIR) -I$(LMLXDIR) -I$(INCLUDES) -L$(LFTDIR) -l$(FTLK) -L$(LFTMTDIR) -l$(FTMTLK) -L$(LMLXDIR) -l$(MLXLK) $(FRAMEWORKS) $(OBJ)
	-@echo "FdF ready."

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -I$(LFTDIR) -I$(LFTMTDIR) -I$(LMLXDIR) -I$(INCLUDES) -c $^

$(LFTDIR)$(LIBFT):
	$(MAKE) -C $(LFTDIR)

$(LFTMTDIR)$(LIBFTMT):
	$(MAKE) -C $(LFTMTDIR)

$(LMLXDIR)$(LIBMLX):
	$(MAKE) -C $(LMLXDIR)

clean:
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(LFTMTDIR) clean
	rm -rf *.h.gch
	rm -rf *.o

fclean: clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(LFTMTDIR) fclean
	$(MAKE) -C $(LMLXDIR) clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

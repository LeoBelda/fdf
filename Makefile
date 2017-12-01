# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 19:02:53 by lbelda            #+#    #+#              #
#    Updated: 2017/12/01 19:06:07 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=srcs/main.c \
	srcs/fdf.c \
	srcs/init/init_geometry.c \
	srcs/init/init_colors.c \
	srcs/init/init_colorprogs.c \
	srcs/init/init_controls.c \
	srcs/init/init_overlay.c \
	\
	srcs/parse/parse_map.c \
	\
	srcs/graphics/draw.c \
	srcs/graphics/colors.c \
	srcs/graphics/color_progs.c \
	srcs/graphics/matrices.c \
	srcs/graphics/vertices_pipeline.c \
	srcs/graphics/callbacks.c \
	srcs/graphics/background.c \
	srcs/graphics/text_overlay.c \
	\
	srcs/algos/bresenham.c \
	srcs/algos/bresenham_clip.c \
	srcs/algos/bresenham_tools.c \
	\
	srcs/controls/callbacks.c \
	srcs/controls/kb_camrotx.c \
	srcs/controls/kb_camroty.c \
	srcs/controls/kb_camrotz.c \
	srcs/controls/kb_camtrsx.c \
	srcs/controls/kb_camtrsy.c \
	srcs/controls/kb_camtrsz.c \
	srcs/controls/kb_chpov.c \
	srcs/controls/kb_chcolor.c \
	srcs/controls/kb_misc.c \
	\
	srcs/utils/print_db.c

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
	rm -rf $(INCLUDES)/*.h.gch
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(LFTMTDIR) fclean
	$(MAKE) -C $(LMLXDIR) clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

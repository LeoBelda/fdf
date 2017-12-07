# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 19:02:53 by lbelda            #+#    #+#              #
#    Updated: 2017/12/07 10:05:10 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=srcs/main.c \
	srcs/fdf.c \
	srcs/init/init_geometry.c \
	srcs/init/init_geometrypresets.c \
	srcs/init/init_dstfuncs.c \
	srcs/init/init_colors.c \
	srcs/init/init_colorprogs.c \
	srcs/init/init_colorfuncs.c \
	srcs/init/init_controls.c \
	srcs/init/init_overlay.c \
	srcs/init/init_sound.c \
	srcs/init/init_soundprogs.c \
	srcs/init/states.c \
	\
	srcs/parse/parse_map.c \
	srcs/parse/active_vtx.c \
	\
	srcs/sound/sound_data.c \
	srcs/sound/sound_map.c \
	srcs/sound/sr_programs.c \
	srcs/sound/sound_color.c \
	srcs/sound/sc_programs.c \
	\
	srcs/graphics/draw.c \
	srcs/graphics/colors.c \
	srcs/graphics/color_progs.c \
	srcs/graphics/dst_map.c \
	srcs/graphics/dst_programs.c \
	srcs/graphics/vdst_programs.c \
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
	srcs/controls/tools.c \
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

FMODDIR=fmod/
FMODLK=fmodL

LMLXDIR=minilibx/
LIBMLX=libmlx.a
MLXLK=mlx
FRAMEWORKS=-framework OpenGL -framework AppKit

NAME=fdf
CC=gcc
CFLAGS=-O3 -Wall -Wextra -Werror
MAKE=make
INT=install_name_tool -change

all: $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT) $(LFTMTDIR)$(LIBFTMT) $(LMLXDIR)$(LIBMLX)
	-@$(CC) -O3 -o $(NAME) -I$(LFTDIR) -I$(LFTMTDIR) -I$(LMLXDIR) -I$(INCLUDES) -L$(LFTDIR) -l$(FTLK) -L$(LFTMTDIR) -l$(FTMTLK) -L$(FMODDIR) -l$(FMODLK) -L$(LMLXDIR) -l$(MLXLK) $(FRAMEWORKS) $(OBJ)
	$(INT) @rpath/libfmodL.dylib $(FMODDIR)libfmodL.dylib $(NAME)
	-@echo "FdF ready."

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -I$(LFTDIR) -I$(LFTMTDIR) -I$(FMODDIR) -I$(LMLXDIR) -I$(INCLUDES) -c $^

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

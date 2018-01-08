# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 19:02:53 by lbelda            #+#    #+#              #
#    Updated: 2018/01/08 12:04:23 by lbelda           ###   ########.fr        #
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
	srcs/init/init_controlspresets.c \
	srcs/init/init_starbox.c \
	srcs/init/init_overlay.c \
	srcs/init/init_sound.c \
	srcs/init/init_soundprogs.c \
	srcs/init/states.c \
	\
	srcs/parse/parse_map.c \
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
	srcs/graphics/active_vtx.c \
	srcs/graphics/callbacks.c \
	srcs/graphics/background.c \
	srcs/graphics/text_overlay.c \
	srcs/graphics/stars/starbox.c \
	srcs/graphics/stars/basics1.c \
	srcs/graphics/stars/nova1.c \
	srcs/graphics/stars/nova2.c \
	srcs/graphics/stars/pt.c \
	\
	srcs/rt/rtcore.c \
	srcs/rt/sdfs.c \
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
	srcs/controls/ps3_camrot.c \
	srcs/controls/ps3_camtrs.c \
	srcs/controls/tools.c \
	\
	srcs/utils/print_db.c \
	srcs/utils/threads.c

OBJ=$(SRC:%.c=%.o)
INCLUDES=includes/
HEADER=fdf.h

LIBPATH=libs/

LFTDIR=$(LIBPATH)libft/
LIBFT=libft.a
FTLK=ft

LFTMTDIR=$(LIBPATH)libftmath/
LIBFTMT=libftmath.a
FTMTLK=ftmath

LSHDDIR=$(LIBPATH)libshader/
LIBSHD=libshader.a
SHDLK=shader

FMODDIR=$(LIBPATH)fmod/
FMODLK=fmodL

LMLXDIR=$(LIBPATH)minilibx/
LIBMLX=libmlx.a
MLXLK=mlx
FRAMEWORKS=-framework OpenGL -framework AppKit

LSDLDIR=$(LIBPATH)SDL2/lib/
LSDLROOT=$(LIBPATH)SDL2/
LSDLSRC=$(LIBPATH)SDL2/sources/
LSDLINCDIR=$(LIBPATH)SDL2/include/SDL2/
LIBSDL=libSDL2.a
SDLLK=SDL2

ALLINCS=-I$(LFTDIR) -I$(LFTMTDIR) -I$(LSHDDIR) -I$(LMLXDIR) -I$(FMODDIR) -I$(LSDLINCDIR) -I$(INCLUDES)

NAME=fdf

CC=gcc
CFLAGS=-O3 -Wall -Wextra -Werror
MAKE=make
INT=install_name_tool -change

all: $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT) $(LFTMTDIR)$(LIBFTMT) $(LSHDDIR)$(LIBSHD) $(LMLXDIR)$(LIBMLX)
	-@$(CC) -O3 -o $(NAME) $(ALLINCS) -L$(LFTDIR) -l$(FTLK) -L$(LFTMTDIR) -l$(FTMTLK) -L$(LSHDDIR) -l$(SHDLK) -L$(FMODDIR) -l$(FMODLK) -L$(LMLXDIR) -l$(MLXLK) -L$(LSDLDIR) -l$(SDLLK) $(FRAMEWORKS) $(OBJ)
	$(INT) @rpath/libfmodL.dylib $(FMODDIR)libfmodL.dylib $(NAME)
	-@echo "FdF ready."

%.o: %.c $(LSDLINCDIR)
	$(CC) $(CFLAGS) -o $@ $(ALLINCS) -c $<

$(LFTDIR)$(LIBFT):
	$(MAKE) -C $(LFTDIR)

$(LFTMTDIR)$(LIBFTMT):
	$(MAKE) -C $(LFTMTDIR)

$(LSHDDIR)$(LIBSHD):
	$(MAKE) -C $(LSHDDIR)

$(LMLXDIR)$(LIBMLX):
	$(MAKE) -C $(LMLXDIR)

$(LSDLINCDIR):
	cd $(LSDLSRC) && ./configure --prefix=$$PWD/../
	$(MAKE) -C $(LSDLSRC) install

clean:
	$(MAKE) -C $(LFTDIR) clean
	$(MAKE) -C $(LFTMTDIR) clean
	$(MAKE) -C $(LSDLSRC) clean
	rm -rf $(INCLUDES)/*.h.gch
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LFTDIR) fclean
	$(MAKE) -C $(LFTMTDIR) fclean
	$(MAKE) -C $(LMLXDIR) clean
	$(MAKE) -C $(LSDLSRC) uninstall
	rm -rf $(LSDLROOT)bin
	rm -rf $(LSDLROOT)include
	rm -rf $(LSDLROOT)lib
	rm -rf $(LSDLROOT)share
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

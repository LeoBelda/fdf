# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 19:02:53 by lbelda            #+#    #+#              #
#    Updated: 2018/03/16 18:28:34 by lbelda           ###   ########.fr        #
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
	srcs/graphics/stars/nova3.c \
	srcs/graphics/stars/nova4.c \
	srcs/graphics/stars/pt.c \
	srcs/graphics/legacy_funcs.c \
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
	srcs/controls/sdl_events.c \
	srcs/controls/ps3_camrot.c \
	srcs/controls/ps3_camtrs.c \
	srcs/controls/tools.c \
	\
	srcs/utils/clean.c \
	srcs/utils/clean_lst.c \
	srcs/utils/print_db.c \
	srcs/utils/threads.c

OBJ=$(SRC:%.c=%.o)
INCDIR=includes/
INCFILES=fdf.h
INC=$(addprefix $(INCDIR), $(INCFILES))

LIBPATH=libs/

LFTDIR=libft/
LFTPATH=$(addprefix $(LIBPATH), $(LFTDIR))
LIBFT=libft.a
FTLK=ft

LFTMTDIR=libftmath/
LFTMTPATH=$(addprefix $(LIBPATH), $(LFTMTDIR))
LIBFTMT=libftmath.a
FTMTLK=ftmath

LSHDDIR=libshader/
LSHDPATH=$(addprefix $(LIBPATH), $(LSHDDIR))
LIBSHD=libshader.a
SHDLK=shader

FMODDIR=fmod/
FMODPATH=$(addprefix $(LIBPATH), $(FMODDIR))
FMODLK=fmodL

LMLXDIR=minilibx/
LMLXPATH=$(addprefix $(LIBPATH), $(LMLXDIR))
LIBMLX=libmlx.a
MLXLK=mlx
FRAMEWORKS=-framework OpenGL -framework AppKit

LSDLDIR=$(LIBPATH)SDL2/lib/
LSDLROOT=$(LIBPATH)SDL2/
LSDLSRC=$(LIBPATH)SDL2/sources/
LSDLINCDIR=$(LIBPATH)SDL2/include/SDL2/
LIBSDL=libSDL2.a
SDLLK=SDL2

ALLINCS=-I$(LFTPATH) -I$(LFTMTPATH) -I$(LSHDPATH) -I$(LMLXPATH) -I$(FMODPATH) -I$(LSDLINCDIR) -I$(INCDIR)

NAME=fdf

CC=gcc
CFLAGS=-O3 -Wall -Wextra -Werror -g
MAKE=make
INT=install_name_tool -change

all: $(NAME)

$(NAME): $(LSDLDIR)$(LIBSDL) $(LFTPATH)$(LIBFT) $(LFTMTPATH)$(LIBFTMT) $(LSHDPATH)$(LIBSHD) $(LMLXPATH)$(LIBMLX) $(OBJ) $(INC)
	$(CC) -O3 -o $(NAME) $(ALLINCS) -L$(LFTPATH) -l$(FTLK) -L$(LFTMTPATH) -l$(FTMTLK) -L$(LSHDPATH) -l$(SHDLK) -L$(FMODPATH) -l$(FMODLK) -L$(LMLXPATH) -l$(MLXLK) -L$(LSDLDIR) -l$(SDLLK) $(FRAMEWORKS) $(OBJ)
	$(INT) @rpath/libfmodL.dylib $(FMODPATH)libfmodL.dylib $(NAME)
	-@echo "FdF ready."

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -o $@ $(ALLINCS) -c $<

$(LFTPATH)$(LIBFT):
	$(MAKE) -C $(LFTPATH)

$(LFTMTPATH)$(LIBFTMT):
	$(MAKE) -C $(LFTMTPATH)

$(LSHDPATH)$(LIBSHD):
	$(MAKE) -C $(LSHDPATH)

$(LMLXPATH)$(LIBMLX):
	$(MAKE) -C $(LMLXPATH)

$(LSDLDIR)$(LIBSDL):
	cd $(LSDLSRC) && ./configure --prefix=$$PWD/../
	$(MAKE) -C $(LSDLSRC) install

clean:
	$(MAKE) -C $(LFTPATH) clean
	$(MAKE) -C $(LFTMTPATH) clean
	$(MAKE) -C $(LSHDPATH) clean
	$(MAKE) -C $(LSDLSRC) clean
	rm -rf $(INCDIR)/*.h.gch
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	$(MAKE) -C $(LFTMTPATH) fclean
	$(MAKE) -C $(LSHDPATH) fclean
	$(MAKE) -C $(LMLXPATH) clean
	$(MAKE) -C $(LSDLSRC) uninstall
	rm -rf $(LSDLROOT)bin
	rm -rf $(LSDLROOT)include
	rm -rf $(LSDLROOT)lib
	rm -rf $(LSDLROOT)share
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

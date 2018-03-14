# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:59:44 by lbelda            #+#    #+#              #
#    Updated: 2018/03/14 09:59:06 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=vec4cf_to_rgb.c \
	pos_to_vec2f.c \
	\
	rgbi_interi.c \
	rgbi_interi_ltd.c \
	rgb_xblend.c \
	rgb_mix.c \
	rgb_mix_ltd.c \
	\
	vec_length.c \
	vec_normalize.c \
	scal_vec.c \
	add_vec.c \
	sub_vec.c \
	\
	step.c
	
OBJ=$(SRC:%.c=%.o)
NAME=libshader.a
CC=gcc
CFLAGS=-Ofast -flto -march=native -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) libshader.h
	-@ar rc $(NAME) $(OBJ)
	-@ranlib $(NAME)
	-@echo "Libshader ready."

%.o: %.c libshader.h
	-@$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

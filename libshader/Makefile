# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:59:44 by lbelda            #+#    #+#              #
#    Updated: 2017/12/12 05:36:37 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=vec4cf_to_rgb.c \
	pos_to_vec2f.c \
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
CFLAGS=-O3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	-@ar rc $(NAME) $(OBJ)
	-@ranlib $(NAME)
	-@echo "Libshader ready."

%.o: %.c
	-@$(CC) $(CFLAGS) -c $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:59:44 by lbelda            #+#    #+#              #
#    Updated: 2017/11/25 13:37:44 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=rgbnew.c \
	rgbcpy.c \
	rgb_to_int.c \
	rgb_interi.c \
	vec2rnewd.c \
	vec2rnewi.c \
	vec4new.c \
	mat4new.c \
	idmat4new.c \
	sclmat4new.c \
	trsmat4new.c \
	rotxmat4new.c \
	rotymat4new.c \
	rotzmat4new.c \
	orthomat4new.c \
	persmat4new.c \
	frustrumnew.c \
	\
	cross_product.c \
	norm_vec4.c \
	vec4xvec4.c \
	mat4xvec4.c \
	mat4xmat4.c \
	\
	deg_rad.c \
	iabs.c \
	\
	print_rgb_fd.c \
	print_rgb.c \
	print_double_fd.c \
	print_double.c \
	print_vec4_fd.c \
	print_vec4.c \
	print_vec2r_fd.c \
	print_vec2r.c \
	print_mat4_fd.c \
	print_mat4.c \
	
OBJ=$(SRC:%.c=%.o)
NAME=libftmath.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	-@ar rc $(NAME) $(OBJ)
	-@ranlib $(NAME)
	-@echo "Libftmath ready."

%.o: %.c
	-@$(CC) $(CFLAGS) -c $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

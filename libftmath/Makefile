# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:59:44 by lbelda            #+#    #+#              #
#    Updated: 2017/11/19 20:04:55 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=vec4new.c \
	mat4new.c \
	idmat4new.c \
	sclmat4new.c \
	\
	cross_product.c \
	norm_vec4.c \
	vec4xvec4.c \
	mat4xvec4.c \
	mat4xmat4.c \
	\
	print_double_fd.c \
	print_double.c \
	print_vec4_fd.c \
	print_vec4.c \
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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbelda <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:59:44 by lbelda            #+#    #+#              #
#    Updated: 2017/11/17 19:55:55 by lbelda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC=ft_cross_product.c
	
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

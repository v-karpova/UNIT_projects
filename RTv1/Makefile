#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 19:06:13 by vkarpova          #+#    #+#              #
#    Updated: 2018/09/26 19:06:14 by vkarpova         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RTv1

SRC = *.c\
		

OBJ = $(SRC:.c=.o)

HEAD = RTv1.h

all:	$(NAME)

$(NAME):
	make -C libft re
	gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -pthread $(SRC) libft/libft.a -o $(NAME) -lm

%.o:%.c $(HEAD)
	gcc -o $@ -c $< -I ./libft/

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re:		fclean all

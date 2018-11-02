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

NAME = fdf

SRC = buttons.c\
		draw.c\
		ft_atoi_base.c\
		main.c\
		moves.c\
		mouse.c\
		work.c

OBJ = $(SRC:.c=.o)

HEAD = fdf.h

all:	$(NAME)

$(NAME):
	make -C libft re
	gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(SRC) libft/libft.a -o $(NAME) -lm

%.o:%.c #HEADER#
	gcc -o $@ -c $< -I ./libft/

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re:		fclean all

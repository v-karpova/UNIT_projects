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

NAME = RT

SRC = calc_vector.c\
		do.c\
		fig_data.c\
		intersect.c\
		light.c\
		main.c\
		normals.c\
		read.c\
		rotation.c\
		save_fig.c\
		save.c\
		save2.c\
		*.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEAD = rt.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME) -framework OpenGL -framework AppKit -lmlx

%.o:%.c $(HEAD)
	gcc $(FLAGS) -o $@ -c $< -I libft

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re:		fclean all

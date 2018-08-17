/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:48:52 by vkarpova          #+#    #+#             */
/*   Updated: 2018/08/17 16:49:39 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

typedef struct 		s_all
{
	void *mlx_ptr;
    void *win_ptr;
	t_matrix	matrix;


}					t_all;

typedef struct	s_matrix
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_matrix;

#endif

int     ft_words(char *s, char c);
void    read_file(char **argv);

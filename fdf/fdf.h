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

#define WIN_X 2000
#define WIN_Y 1000
#define MAX_X all->map_x
#define MAX_Y all->map_y
#define MLX_PTR all->mlx_ptr
#define WIN_PTR all->win_ptr
// # define
// # define
// # define


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "math.h"
#include "mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"

typedef struct	s_matrix
{
	double		x;
	double		y;
	double		z;
	int		color;
}				t_matrix;

typedef struct 		s_all
{
	void		*mlx_ptr;
    void		*win_ptr;
	t_matrix	**matrix;
	int			map_x;
	int			map_y;
	double		center[3];

}					t_all;


#endif

void		error_msg(int code);
int			ft_words(char *s, char c);
t_all		*read_file(char **argv, t_all *all);
t_matrix	*save_coords(char *line, int line_nb, t_all *all);
void		go(t_all *all);
void  		draw(t_all *all);
void    	print(t_matrix **matrix, int max_x, int max_y);
void   		make_line(t_all *all, t_matrix *dot1, t_matrix *dot2);
void  		to_center(t_all *all);
int			event(int key, t_all *all);
void  		zoom(t_all *all, int how);
void  		make_bigger(t_all *all);

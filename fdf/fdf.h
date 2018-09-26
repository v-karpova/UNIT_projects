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

#define WIN_X 2550
#define WIN_Y 1300
#define BIGGER 40
#define MAX_X all->map_x
#define MAX_Y all->map_y
#define MLX_PTR all->mlx_ptr
#define WIN_PTR all->win_ptr

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "math.h"
#include "mlx.h"
#include "libft/libft.h"
#include "get_next_line.h"

typedef struct		s_matrix
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_matrix;

typedef struct		s_mouse
{
	char		press;
	int			x;
	int			y;
}					t_mouse;

typedef struct		s_all
{
	t_mouse		mouse;
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
t_all		*read_file(char **argv, t_all *all, int fd);
t_matrix	*save_coords(char *line, int line_nb, t_all *all);
void		note(t_all *all);
void		go(t_all *all);
void		draw(t_all *all);
int			event1(int key, t_all *all);
void		event2(int key, t_all *all);
void		event3(int key, t_all *all);
void		event4(int key, t_all *all);
void		event5(int key, t_all *all);
void		z_moves(t_all *all, int how);
void		color_move(t_all *all, int how);
void		make_line(t_all *all, t_matrix *dot1, t_matrix *dot2);
int			event(int key, t_all *all);
void		zoom(t_all *all, int how);
void		move(t_all *all, int where);
void		move_to_center(t_all *all);
void		find_center(t_all *all);
void		rotat_x(t_all *all, double angle);
void		rotat_y(t_all *all, double angle);
void		rotat_z(t_all *all, double angle);
void		move_to(t_all *all, int where);
int			ft_atoi_base(const char *str, int str_base);
int			main(int argc, char **argv);
int			mouse_press(int button, int x, int y, t_all *all);
int			mouse_release(int button, int x, int y, t_all *all);
int			mouse_move(int x, int y, t_all *all);
int			x_close(t_all *all);

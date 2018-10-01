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

# define WIN_X 2550
# define WIN_Y 1300
# define BIGGER 40
# define MAX_X all->map_x
# define MAX_Y all->map_y
# define MLX_PTR all->mlx_ptr
# define WIN_PTR all->win_ptr

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "math.h"
# include "mlx.h"
# include "libft/libft.h"

typedef struct	s_matrix
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_matrix;

typedef struct	s_mouse
{
	char		press;
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_all
{
	t_mouse		mouse;
	void		*mlx_ptr;
	void		*win_ptr;
	t_matrix	**matrix;
	int			map_x;
	int			map_y;
	double		center[3];
}				t_all;

int				event1(int key, t_all *all);
void			event2(int key, t_all *all);
void			event3(int key, t_all *all);
void			event4(int key, t_all *all);
void			event5(int key, t_all *all);
void			color_move(t_all *all, int how);
void			note(t_all *all);
void			go(t_all *all);
void			draw(t_all *all);
void			make_line(t_all *all, t_matrix *c1, t_matrix *c2);
void			error_msg(int code);
int				ft_words(char *s, char c);
t_all			*read_file(t_all *all, int fd);
int				main(int argc, char **argv);
void			make_free(char **arr);
void			make_free_m(t_matrix **arr);
void			move(t_all *all, int where);
void			rotat_x(t_all *all, double angle);
void			rotat_y(t_all *all, double angle);
void			rotat_z(t_all *all, double angle);
void			zoom(t_all *all, int how);
t_matrix		*save_coords(char *line, int line_nb, t_all *all);
void			move_to(t_all *all, int where);
void			find_center(t_all *all);
void			move_to_center(t_all *all);
int				mouse_press(int button, int x, int y, t_all *all);
int				mouse_release(int button, int x, int y, t_all *all);
int				mouse_move(int x, int y, t_all *all);
int				x_close(t_all *all);
int				ft_atoi_base_16(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:34:28 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/01 17:34:31 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define WIN_X 1000
# define WIN_Y 1000
# define MLX_PTR all->mlx_ptr
# define WIN_PTR all->win_ptr
# define IMG_PTR all->img_ptr
# define X all->x
# define Y all->y
# define X1 all->x1
# define Y1 all->y1
# define MV_X all->move_x
# define MV_Y all->move_y
# define CH_Y all->change_y
# define CH_X all->change_x
# define ZOOM all->zoom
# define COLOR all->color
# define IMG_H WIN_Y
# define IMG_W WIN_Y
# define MAX_ITER all->iter
# define CR all->c_r
# define CI all->c_i
# define ZR all->Z_r
# define ZI all->Z_i
# define ZR2 all->Z_r2
# define ZI2 all->Z_i2

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include "math.h"
# include "mlx.h"
# include "libft/libft.h"

typedef struct	s_mouse
{
	char		press;
	double		x;
	double		y;
}				t_mouse;

typedef struct	s_all
{
	t_mouse		mouse;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	double		x;
	double		y;
	double		x1;
	double		y1;
	int			stop;
	double		mouse_x;
	double		mouse_y;
	double		x_max;
	int			iter;
	int			fract;
	int			size_line;
	int			bpp;
	int			endian;
	double		move_x;
	double		move_y;
	int			color;
	double		zoom;
	char		*img;
	double		c_r;
	double		c_i;
	double		Z_r;
	double		Z_i;
	double		Z_r2;
	double		Z_i2;
	double		ji;
	double		jr;
	int			isInside;
}				t_all;

void	go(t_all *all, int n);
void	now_do(t_all *all, int n);
void	set_img(t_all *all, int n);
void	pixel_put_img(t_all *all, int x, int y, int color);
int		main(int argc, char **argv);
int		event(int key, t_all *all);
int		mouse_press(int button, int x, int y, t_all *all);
int		mouse_release(int button, int x, int y, t_all *all);
int		mouse_move(int x, int y, t_all *all);
int		x_close(t_all *all);
int		name_check(char **argv);
int		jul(t_all *all);
void	*mandelbrot(void *v);
void	mandelbrot_thread(t_all *all);
void	julia_thread(t_all *all);
void	forever_thread(t_all *all);
void	heart_thread(t_all *all);
void	mandelbar_thread(t_all *all);
void	rabbit_thread(t_all *all);
void	snowflake_thread(t_all *all);
void	tricorn_thread(t_all *all);
void	*julia(void *v);
void	*forever(void *v);
void	*rabbit(void *v);
void	*heart(void *v);
void	*tricorn(void *v);
void	*mandelbar(void *v);
void	*snowflake(void *v);
int		color(t_all *all, int iter);
void	note(t_all *all);

#endif

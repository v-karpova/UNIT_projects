/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 19:46:19 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/16 19:46:48 by vkarpova         ###   ########.fr       */
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
# define MV_X all->move_x
# define MV_Y all->move_y
# define ZOOM all->zoom
# define COLOR all->color
# define IMG_H WIN_Y
# define IMG_W WIN_Y
# define MAX_ITER all->iter
# define CR all->c_r
# define CI all->c_i
# define ZR all->z_r
# define ZI all->z_i
# define ZR2 all->z_r2
# define ZI2 all->z_i2

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
	double		z_r;
	double		z_i;
	double		z_r2;
	double		z_i2;
	double		ji;
	double		jr;
}				t_all;

void			pixel_put_img(t_all *all, int x, int y, int color);
void			now_do(t_all *all, int n);
int				event(int key, t_all *all);
void			event1(int key, t_all *all);
void			event2(int key, t_all *all);
void			event3(int key, t_all *all);
void			event4(int key, t_all *all);
void			forever_thread(t_all *all);
void			*forever(void *v);
void			c_forever(t_all *all);
void			heart_thread(t_all *all);
void			*heart(void *v);
void			c_heart(t_all *all, double ci, double cr);
void			julia_thread(t_all *all);
void			*julia(void *v);
void			c_julia(t_all *all);
void			set_img(t_all *all, int n);
void			go(t_all *all, int n);
int				name_check(char **argv);
void			usage(int o);
int				main(int argc, char **argv);
void			mandelbar_thread(t_all *all);
void			*mandelbar(void *v);
void			c_mandelbar(t_all *all, double ci, double cr);
void			mandelbrot_thread(t_all *all);
void			*mandelbrot(void *v);
void			c_mandelbrot(t_all *all, double ci, double cr);
int				mouse_press(int button, int x, int y, t_all *all);
int				mouse_release(int button, int x, int y, t_all *all);
int				mouse_move(int x, int y, t_all *all);
int				x_close(t_all *all);
void			rabbit_thread(t_all *all);
void			*rabbit(void *v);
void			c_rabbit(t_all *all);
void			snowflake_thread(t_all *all);
void			*snowflake(void *v);
void			c_snowflake(t_all *all, double ci, double cr);
void			tricorn_thread(t_all *all);
void			*tricorn(void *v);
void			c_tricorn(t_all *all, double ci, double cr);

#endif

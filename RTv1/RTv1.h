/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:09:21 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/17 15:09:23 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RTV1_H
# define FT_RTV1_H

# define WIN_X 700
# define WIN_Y 700
# define MLX_PTR all->mlx_ptr
# define WIN_PTR all->win_ptr
# define IMG_PTR all->img_ptr
# define X vector->x
# define Y vector->y
# define Z vector->z

# define ZOOM all->zoom
# define COLOR all->color

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

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		res;

	double		t1;
	double		t2;
	double		t;

}				t_vector;


typedef struct s_light
{
	t_vector	pos;
	t_vector	direction;
	int			type;
	double		intens;
}				t_light;


typedef struct s_plane
{
	double		r;
	t_vector	c;
	t_vector	v;
	int			color;
	double		reflect;
}				t_plane;

typedef struct s_cylinder
{
	double		r;
	t_vector	c;
	t_vector	v;
	int			color;
	double		reflect;
}				t_cylinder;

typedef struct s_sphere
{
	double		r;
	t_vector	c;
	int			color;
	double		reflect;
}				t_sphere;

typedef struct s_cone
{
	double		r;
	double		k;
	t_vector	c;
	t_vector	v;
	int			color;
	double		reflect;
}				t_cone;

typedef struct	s_all
{
	t_mouse		mouse;
	t_vector	vector;
	t_vector	view;
	t_vector	N;
	t_vector	cam;
	t_sphere	sphere;
	t_cone		cone;
	t_plane		plane;
	t_cylinder	cylinder;
	t_light		light;


	double		d;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	double		x;
	double		y;
	int			size_line;
	int			bpp;
	int			endian;
	int			color;
	double		zoom;
	char		*img;
}				t_all;

int			is_in_sphere(t_vector *vector);
void		sphere(t_all *all);
void		cone(t_all *all);
void		plane(t_all *all);
void		cylinder(t_all *all);
void		do_it(t_all *all);
int			event(int key, t_all *all);
t_vector	send_ray(int x, int y);
void		color_pixel(double x, double y);
void		pixel_put_img(t_all *all, int x, int y, int color);
t_vector	minus(t_vector a, t_vector b);
double		umnozh(t_vector a, t_vector b);
double		dlinna(t_vector a);
t_vector	scal(t_vector a, t_vector b);
t_vector	times(double n, t_vector a);
t_vector	plus(t_vector a, t_vector b);
int		ReflectedColor(t_all *all, double closest);
int		TraceRay(t_all *all);
t_vector	int_to_rgb(int rgb);
int		rgb_to_int(t_vector C);
int		mouse_release(int button, int x, int y, t_all *all);
int		mouse_move(int x, int y, t_all *all);
int		x_close(t_all *all);
int		mouse_press(int button, int x, int y, t_all *all);
void	cone(t_all *all);


#endif


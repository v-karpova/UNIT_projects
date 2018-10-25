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

# define WIN_X 500
# define WIN_Y 500
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

// typedef struct	s_mouse
// {
// 	char		press;
// 	double		x;
// 	double		y;
// }				t_mouse;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	double		res;

	double		t1;
	double		t2;

}				t_vector;

typedef struct s_sphere
{
	double		r;
	t_vector	c;
	int			color;
}				t_sphere;

typedef struct	s_all
{
	// t_mouse		mouse;
	t_vector	vector;
	t_vector	view;
	t_vector	cam;
	t_sphere	sphere;

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


#endif


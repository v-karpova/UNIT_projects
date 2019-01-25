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

# define WIN_X 1000
# define WIN_Y 1000
# define MLX_PTR all->mlx_ptr
# define WIN_PTR all->win_ptr
# define IMG_PTR all->img_ptr

# define PLANE 100
# define SPHERE 101
# define CYL 102
# define CONE 103
# define LIGHT 104
# define CAM 105

# define COLOR all->color
// # define FON 0xF696969
# define FON 0xFFEFFCD

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

typedef struct	s_clos
{
	t_list		*obj;
	double		clost;
	double		y;
}				t_clos;

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
	double		intense;
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
	double		a;
	t_vector	c;
	t_vector	v;
	int			color;
	double		reflect;
}				t_cone;

typedef struct s_obj
{
	t_sphere	*sphere;
	t_cone		*cone;
	t_plane		*plane;
	t_cylinder	*cylinder;
}				t_obj;

typedef struct	s_vec
{
	t_vector	D;
	t_vector	V;
	t_vector	N;
	t_vector	P;
	t_vector	L;
	t_vector	O;

}				t_vec;

typedef struct	s_all
{
	t_mouse		mouse;

	t_clos		clos;

	t_vector	cam;
	t_list		*obj;
	t_list		*light;
	
	int			fd;
	double		closest;
	double		d;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img;

	int			size_line;
	int			bpp;
	int			endian;
	int			color;

}				t_all;

void		do_it(t_all *all);
int			event(int key, t_all *all);
t_vector	send_ray(int x, int y);
void		color_pixel(double x, double y);
void		pixel_put_img(t_all *all, int x, int y, int color);
t_vector	minus(t_vector a, t_vector b);
double		dot(t_vector a, t_vector b);
double		dlinna(t_vector a);
t_vector	scal(t_vector a, t_vector b);
t_vector	times(double n, t_vector a);
t_vector	plus(t_vector a, t_vector b);
t_vector	norm(t_vector a);
t_vector	check_color(t_vector color);
int		TraceRay(t_all *all, t_list *list, t_vector O, t_vector D);
t_vector	int_to_rgb(int rgb);
int			rgb_to_int(t_vector C);
int			mouse_release(int button, int x, int y, t_all *all);
int			mouse_move(int x, int y, t_all *all);
int			x_close(t_all *all);
int			mouse_press(int button, int x, int y, t_all *all);
void		cone(t_all *all);
void		read_file(t_obj *obj, t_all *all);
void		open_file(char **argv, t_obj *obj, t_all *all);
void		error(int n);
int			save_cone(t_all *all);
int			save_plane(t_all *all);
int			save_cylinder(t_all *all);
int			save_sphere(t_all *all);
int			save_light(t_all *all);
int			save_color(t_all *all, int *color);
int			save_radius(t_all *all, double *radius);
int			save_pos(t_all *all, t_vector *pos);
int			save_intense(t_all *all, double *intense);
int			save_angle(t_all *all, double *angle);
int			save_reflect(t_all *all, double *reflect);
int			save_normal(t_all *all, t_vector *norm);
int			save_center(t_all *all, t_vector *center);
t_vector	save_cam(char *line);
t_vector	IntersectRay(t_list *list, t_vector O, t_vector D);
t_vector	IntersectRaySphere(t_sphere *sphere, t_vector O, t_vector D);
t_vector	IntersectRayCylinder(t_cylinder *cylinder, t_vector O, t_vector D);
t_vector	IntersectRayCone(t_cone *cone, t_vector O, t_vector D);
t_vector	IntersectRayPlane(t_plane *plane, t_vector O, t_vector D);
t_vector	CanvasToViewport(t_all *all, double x, double y);
void		print(t_obj *obj, t_all *all);
int			light_sphere(t_light *light, t_all *all, t_sphere *sphere);
int			light_plane(t_light *light, t_all *all, t_plane *plane);
int			light_cone(t_light *light, t_all *all, t_cone *cone);
int			light_cyl(t_light *light, t_all *all, t_cylinder *cyl);
t_clos		closer_obj(t_list *list, t_vector O, t_vector D, double min);
double		calc_reflect(double reflect, t_vector N, t_all *all, t_light *light);
double		ComputeLighting(t_all *all, t_vector N, double s);
t_vector	ReflectRay(t_vector L, t_vector N);
double		fig_specular(t_list *list);
t_vector	fig_center(t_list *list);
int			fig_color(t_list *list);
int			color(double i, double j, t_clos clos);
double		spec(double spec, double intense, t_vec *vec);
double		diff(double intense, t_vec *vec);
int		ReflectedColor(t_all *all, t_clos clos, t_vec *vec);
void	find_normal(t_vec *vec, t_clos *clos);
void	norm_cone(t_vec *vec, double t, t_cone *cone);
void	find_normal(t_vec *vec, t_clos *clos);
void	norm_sphr(t_vec *vec, t_sphere *sphr);
void	norm_cyl(t_vec *vec, double t, t_cylinder *cyl);
void	norm_plane(t_vec *vec, t_plane *plan);


#endif


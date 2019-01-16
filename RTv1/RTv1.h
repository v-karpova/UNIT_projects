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

# define PLANE 300
# define SPHERE 301
# define CYL 302
# define CONE 303
# define LIGHT 304
# define CAM 305

# define ZOOM all->zoom
# define COLOR all->color
# define FON 0xF696969

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

typedef struct	s_all
{
	t_mouse		mouse;
	t_vector	vector;
	t_vector	view;
	t_vector	N;
	t_vector	P;
	t_vector	L;
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
	double		x;
	double		y;
	int			size_line;
	int			bpp;
	int			endian;
	int			color;
	double		zoom;
	char		*img;
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
int			TraceRay(t_all *all);
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
int			save_cone(t_all *all, t_obj *obj);
int			save_plane(t_all *all, t_obj *obj);
int			save_cylinder(t_all *all, t_obj *obj);
int			save_sphere(t_all *all, t_obj *obj);
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
t_vector	IntersectRay(t_all *all, t_list *list);
t_vector	IntersectRaySphere(t_all *all, t_sphere *sphere);
t_vector	IntersectRayCylinder(t_all *all, t_cylinder *cylinder);
t_vector	IntersectRayCone(t_all *all, t_cone *cone);
t_vector	IntersectRayPlane(t_all *all, t_plane *plane);
void		CanvasToViewport(t_all *all, double x, double y);
void		print(t_obj *obj, t_all *all);
int			light_sphere(t_light *light, t_all *all, t_sphere *sphere);
int			light_plane(t_light *light, t_all *all, t_plane *plane);
int			light_cone(t_light *light, t_all *all, t_cone *cone);
int			light_cyl(t_light *light, t_all *all, t_cylinder *cyl);
t_clos		closer_obj(t_all *all);
double		calc_reflect(double reflect, t_vector N, t_all *all, t_light *light);
double		ComputeLighting(t_all *all, t_vector N, double s);
t_vector	ReflectRay(t_vector M, t_vector N);
double		fig_specular(t_list *list);
t_vector	fig_center(t_list *list);
int			fig_color(t_list *list);
int			color(double i, double j, t_clos clos);
double		spec(t_list *list, t_all *all, t_light *light);
double		diff(t_list *list, t_all *all, t_light *light);
int		ReflectedColor(t_all *all, t_clos clos);

#endif

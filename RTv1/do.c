// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:01:31 by vkarpova          #+#    #+#             */
/*   Updated: 2018/11/14 14:01:32 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	do_it(t_all *all)
{
	double		x;
	double		y;
	t_vector	D;

	x = -WIN_X / 2 - 1;
	while(x++ < WIN_X / 2)
	{
		y = -WIN_Y / 2;
		while (y++ < WIN_Y / 2)
		{
			D = CanvasToViewport(all, x, y);
			all->color = TraceRay(all, all->obj, all->cam, D);
			pixel_put_img(all, x + WIN_X / 2, WIN_Y / 2 - y, all->color);
		}
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

t_vector	CanvasToViewport(t_all *all, double x, double y)
{
	t_vector	D;

	D.x = (double)(x / WIN_X);
	D.y = (double)(y / WIN_Y);
	D.z = all->d;
	return(D);
}

int		TraceRay(t_all *all, t_list *list, t_vector O, t_vector D)
{
	t_clos		closer;
	t_vec		vec;

	closer.obj = 0;
	closer = closer_obj(list, O, D, 0.1);
	if (closer.obj == NULL)
		return (FON);

	vec.O = O;
	vec.D = D;
	vec.V = minus((t_vector){0, 0, 0}, D);
	vec.P = plus(O, times(closer.clost, D));

	// vec.N = minus(vec.P, fig_center(closer.obj));

	find_normal(&vec, &closer);

	return (ReflectedColor(all, closer, &vec));
}

t_clos		closer_obj(t_list *list, t_vector O, t_vector D, double min)
{
	t_clos		closer;
	t_vector	a;
	// t_list		*list;

	// list = all->obj;
	a = (t_vector){600000, 600000, 600000};
	closer.clost = 600000;
	closer.obj = 0;
	while (list && (list->content_size) > 0)
	{
		a = IntersectRay(list, O, D);
		if (a.t1 >= min && a.t1 <= 600000 && a.t1 < closer.clost)
		{
			closer.obj = list;
			closer.clost =  a.t1;
		}
		if (a.t2 >= min && a.t2 <= 600000 && a.t2 < closer.clost)
		{
			closer.obj = list;
			closer.clost =  a.t2;
		}
		list = list->next;
	}
	return (closer);
}

void	find_normal(t_vec *vec, t_clos *clos)
{
	if ((clos->obj)->content_size == PLANE)
		norm_plane(vec, (t_plane *)((clos->obj)->content));
	else if ((clos->obj)->content_size == SPHERE)
		norm_sphr(vec, (t_sphere *)((clos->obj)->content));
	else if ((clos->obj)->content_size == CYL)
		norm_cyl(vec, clos->clost, (t_cylinder *)((clos->obj)->content));
	else if ((clos->obj)->content_size == CONE)
		norm_cone(vec, clos->clost, (t_cone *)((clos->obj)->content));
}

void	norm_plane(t_vec *vec, t_plane *plan)
{
	if (dot(vec->D, plan->v) < 0)
		vec->N = plan->v;
	else
		vec->N = minus((t_vector){0, 0, 0}, plan->v);
}

void	norm_sphr(t_vec *vec, t_sphere *sphr)
{
	t_vector	v;

	v = minus(vec->P, sphr->c);
	vec->N = norm(v);
}

void	norm_cyl(t_vec *vec, double t, t_cylinder *cyl)
{
	double		m;
	t_vector	OC;

	cyl->v = norm(cyl->v);
	OC = minus(vec->O, cyl->c);
	m = dot(vec->D, times(t, cyl->v)) + dot(OC, cyl->v);
	vec->N = minus(minus(vec->P, cyl->c), times(m, cyl->v));
	vec->N = norm(vec->N);
}

void	norm_cone(t_vec *vec, double t, t_cone *cone)
{
	double		m;
	t_vector	OC;
	t_vector	PC;

	OC = minus(vec->O, cone->c);
	PC = minus(vec->P, cone->c);
	m = dot(vec->D, times(t, cone->v)) + dot(OC, cone->v);
	vec->N = minus(minus(vec->P, cone->c), times(m + cone->a, cone->v));
	vec->N = norm(vec->N);
}


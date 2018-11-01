/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:00:08 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/26 18:00:09 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector		IntersectRayCylinder(t_all *all, t_vector view)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	OC = minus(all->cam, all->cylinder.c);
	k.x = umnozh(view, view) - umnozh(view, all->cylinder.v) * umnozh(view, all->cylinder.v);
	k.y = 2 * (umnozh(OC, view) - umnozh(all->cylinder.v, view) * umnozh(OC, all->cylinder.v));
	k.z = umnozh(OC, OC) - umnozh(OC, all->cylinder.v) * umnozh(OC, all->cylinder.v) - all->cylinder.r * all->cylinder.r;

	disc = k.y * k.y - 4 * k.x * k.z;
	if (disc < 0)
	{
		a.t1 = 100000;
		a.t2 = 100000;
		return (a);
	}
	a.t1 = (-k.y + sqrt(disc)) / (2 * k.x);
	a.t2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (a);
}

void	cyl_norm(t_all *all, double t, t_vector p)
{
	t_vector	OC;
	double		n;

	OC = minus(all->cam, all->cylinder.c);
	n = t * umnozh(all->view, all->cylinder.v) + umnozh(OC, all->cylinder.v);
	all->N = minus(p, minus(all->cylinder.c, times(n, all->cylinder.v)));
	all->N = times((1 / dlinna(all->N)), all->N);
}


void CanvasToViewport_cylinder(t_all *all, double x, double y)
{
	all->view.x = (double)(x / WIN_X);
	all->view.y = (double)(y / WIN_Y);
	all->view.z = all->d;
}

int		TraceRay_cylinder(t_all *all)
{
	t_vector		a;
	t_vector		p;
	double		closest;
	double		closest_cylinder;

	closest = 100000;
	closest_cylinder = 0;

	// p = plus(all->cam, times(a.t, all->view));
	// cyl_norm(all, a.t, p);

	a = IntersectRayCylinder(all, all->view);
	
	if (a.t1 > 0 && a.t1 < 100000 && a.t1 < closest)
	{
		closest = a.t1;
		closest_cylinder = 1;
	}
	if (a.t2 > 0 && a.t2 < 100000 && a.t2 < closest)
	{
		closest = a.t2;
		closest_cylinder = 1;
	}

	if (a.t1 < a.t2)
		a.t = a.t1;
	else
		a.t = a.t2;
		
	p = plus(all->cam, times(a.t, all->view));
	cyl_norm(all, a.t, p);
	if (closest_cylinder == 0)
		return (0xFFFFFFF);
	return (ReflectedColor(all, closest));
}

void	cylinder(t_all *all)
{
	double		x;
	double		y;

	x = -WIN_X / 2 - 1;
	while(x++ < WIN_X / 2)
	{
		y = -WIN_Y / 2;
		while (y++ < WIN_Y / 2)
		{
			CanvasToViewport_cylinder(all, x, y);
			all->color = TraceRay_cylinder(all);
			pixel_put_img(all, x + WIN_X / 2, WIN_Y / 2 - y, all->color);
		}
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

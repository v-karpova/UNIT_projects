/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:59:36 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/26 16:59:45 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector		IntersectRayCone(t_all *all, t_vector view)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;
	
	OC = minus(all->cam, all->cone.c);
	k.x = umnozh(view, view) - (1 + (all->cone.a)*(all->cone.a)) * umnozh(view, all->cone.v) * umnozh(view, all->cone.v);
	k.y = 2 * (umnozh(view, OC) * (1 + (all->cone.a)*(all->cone.a) * umnozh(view, all->cone.v) * umnozh(OC, all->cone.v)));
	k.z = umnozh(view, view) - (1 + (all->cone.a)*(all->cone.a)) * umnozh(OC, all->cone.v) * umnozh(OC, all->cone.v);
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

void CanvasToViewport_cone(t_all *all, double x, double y)
{
	all->view.x = (double)(x / WIN_X);
	all->view.y = (double)(y / WIN_Y);
	all->view.z = all->d;
}

int		TraceRay_cone(t_all *all)
{
	t_vector		a;
	double		closest;
	double		closest_cone;

	closest = 100000;
	closest_cone = 0;
	a = IntersectRayCone(all, all->view);
	
	if (a.t1 > 0 && a.t1 < 100000 && a.t1 < closest)
	{
		closest = a.t1;
		closest_cone = 1;
	}
	if (a.t2 > 0 && a.t2 < 100000 && a.t2 < closest)
	{
		closest = a.t2;
		closest_cone = 1;
	}
	if (closest_cone == 0)
		return (0xFFFFFFF);
	// return (all->cone.color);
	return (ReflectedColor(all, closest));
}

void	cone(t_all *all)
{
	double		x;
	double		y;

	x = -WIN_X / 2 - 1;
	while(x++ < WIN_X / 2)
	{
		y = -WIN_Y / 2;
		while (y++ < WIN_Y / 2)
		{
			CanvasToViewport_cone(all, x, y);
			all->color = TraceRay_cone(all);
			pixel_put_img(all, x + WIN_X / 2, WIN_Y / 2 - y, all->color);
			
		}
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:58:19 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/23 14:58:21 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void CanvasToViewport(t_all *all, double x, double y)
{
	all->view.x = (double)(x / WIN_X);
	all->view.y = (double)(y / WIN_Y);
	all->view.z = all->d;
}

t_vector		IntersectRaySphere(t_all *all, t_vector view)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	OC = minus(all->cam, all->sphere.c);
	k.x = umnozh(view, view);
	k.y = 2 * umnozh(OC, view);
	k.z = umnozh(OC, OC) - all->sphere.r * all->sphere.r;
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

int		TraceRay(t_all *all)
{
	t_vector		a;
	double		closest;
	double		closest_sphere;

	closest = 100000;
	closest_sphere = 0;
	a = IntersectRaySphere(all, all->view);
	
	if (a.t1 > 0 && a.t1 < 100000 && a.t1 < closest)
	{
		closest = a.t1;
		closest_sphere = 1;
	}
	if (a.t2 > 0 && a.t2 < 100000 && a.t2 < closest)
	{
		closest = a.t2;
		closest_sphere = 1;
	}
	if (closest_sphere == 0)
		return (0xFFFFFFF);
	// return (all->sphere.color);
	return (ReflectedColor(all, closest));
}

void	sphere(t_all *all)
{
	double		x;
	double		y;

	x = -WIN_X / 2 - 1;
	while(x++ < WIN_X / 2)
	{
		y = -WIN_Y / 2;
		while (y++ < WIN_Y / 2)
		{
			CanvasToViewport(all, x, y);
			all->color = TraceRay(all);
			pixel_put_img(all, x + WIN_X / 2, WIN_Y / 2 - y, all->color);
			
		}
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

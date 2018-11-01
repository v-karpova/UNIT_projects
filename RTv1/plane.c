/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:59:55 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/26 17:59:57 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector		IntersectRayPlane(t_all *all, t_vector view)
{
	t_vector	OC;
	t_vector	a;
	double		i;
	double		j;

	a.t = 100000;
	OC = minus(all->plane.c, all->cam);
	i = umnozh(all->view, all->plane.v);
	j = umnozh(OC, all->plane.v);
	if (j == 0)
		return (a);
	a.t = i / j;
	return (a);
}

void CanvasToViewport_plane(t_all *all, double x, double y)
{
	all->view.x = (double)(x / WIN_X);
	all->view.y = (double)(y / WIN_Y);
	all->view.z = all->d;
}

int		TraceRay_plane(t_all *all)
{
	t_vector		a;
	double		closest;
	double		closest_plane;

	closest = 100000;
	closest_plane = 0;
	a = IntersectRayPlane(all, all->view);
	
	if (a.t > 0 && a.t < 100000 && a.t < closest)
	{
		closest = a.t;
		closest_plane = 1;
	}
	if (closest_plane == 0)
		return (0xFFFFFFF);
	// return (all->plane.color);
	return (ReflectedColor(all, closest));
}

void	plane(t_all *all)
{
	double		x;
	double		y;

	x = -WIN_X / 2 - 1;
	while(x++ < WIN_X / 2)
	{
		y = -WIN_Y / 2;
		while (y++ < WIN_Y / 2)
		{
			CanvasToViewport_plane(all, x, y);
			all->color = TraceRay_plane(all);
			pixel_put_img(all, x + WIN_X / 2, WIN_Y / 2 - y, all->color);
			
		}
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

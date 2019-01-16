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

void	CanvasToViewport(t_all *all, double x, double y)
{
	all->view.x = (double)(x / WIN_X);
	all->view.y = (double)(y / WIN_Y);
	all->view.z = all->d;
}

int		TraceRay(t_all *all)
{
	t_clos		closer;

	all->closest = 600000;
	closer.obj = 0;
	closer = closer_obj(all);
	if (closer.obj == NULL)
		return (FON);
	all->P = plus(all->cam, times(closer.clost, all->view));
	return (ReflectedColor(all, closer));
}

t_clos		closer_obj(t_all *all)
{
	t_clos		closer;
	t_vector	a;
	t_list		*list;

	closer.clost = 600000;
	closer.obj = 0;
	list = all->obj;
	closer.obj = 0;
	while (list)
	{
		a = IntersectRay(all, list);
		if (a.t1 >= 0.01 && a.t1 <= 600000 && a.t1 < closer.clost)
		{
			closer.obj = list;
			closer.clost =  a.t1;
			all->closest = a.t1;
		}
		if (a.t2 >= 0.01 && a.t2 <= 600000 && a.t2 < closer.clost)
		{
			closer.obj = list;
			closer.clost =  a.t2;
			all->closest = a.t2;
		}
		list = list->next;
	}
	return (closer);
}


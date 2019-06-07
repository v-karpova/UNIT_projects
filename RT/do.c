/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:51:57 by vkarpova          #+#    #+#             */
/*   Updated: 2019/02/01 17:51:58 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			pixel_put_img(t_all *all, int x, int y, int color)
{
	if (x < WIN_X && y < WIN_Y)
	{
		color = mlx_get_color_value(all->mlx_ptr, color);
		ft_memcpy(all->img + 4 * WIN_X * y + x * 4, &color, sizeof(int));
	}
	all->img =
	mlx_get_data_addr(all->img_ptr, &all->bpp, &all->size_line, &all->endian);
}

void			do_it(t_all *all)
{
	double		x;
	double		y;
	t_vector	d;

	x = -WIN_X / 2 - 1;
	while (x++ < WIN_X / 2)
	{
		y = -WIN_Y / 2;
		while (y++ < WIN_Y / 2)
		{
			all->depth_refl = 0;
			all->depth_refl_spec = 0;
			all->depth_transp = 0;
			d = rotation(all, canvas_to_viewport(all, x, y));
			all->color = trace_ray(all, all->obj, all->cam, d);
			pixel_put_img(all, x + WIN_X / 2, WIN_Y / 2 - y, all->color);
		}
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

t_vector		canvas_to_viewport(t_all *all, double x, double y)
{
	t_vector	d;

	d.x = (double)(x / WIN_X);
	d.y = (double)(y / WIN_Y);
	d.z = all->d;
	return (d);
}

int				trace_ray(t_all *all, t_list *list, t_vector o, t_vector d)
{
	t_clos		closer;
	t_vec		vec;
	t_vector			color;
	t_vector			local_color;

	closer.obj = 0;
	closer = closer_obj(list, o, d, 0.1);
	if (closer.obj == NULL)
		return (FON);
	vec.o = o;
	vec.d = d;
	vec.v = minus(init_vector(0, 0, 0, 0), d);
	vec.p = plus(o, times(closer.clost, d));
	fig_normal(&vec, &closer);

	color = init_vector(0,0,0,0);
	if (closer.obj != NULL)
	{
		local_color = int_to_rgb(reflected_color(all, closer, &vec));
		if ((fig_reflect(closer.obj)) > 0)
			color = plus(color, reflect(all, &vec, closer, local_color));
		if (fig_transp(closer.obj) > 0)
			color = plus(color, transp(all, &vec, closer, local_color));
		if ((fig_reflect(closer.obj)) == 0 && (fig_transp(closer.obj) == 0))
			color = local_color;
	}
	return (rgb_to_int(color));
}

t_clos			closer_obj(t_list *list, t_vector o, t_vector d, double min)
{
	t_clos		closer;
	t_vector	a;

	a = init_vector(600000, 600000, 600000, 600000);
	closer.clost = 600000;
	closer.obj = 0;
	while (list && (list->content_size) > 0)
	{
		a = intersect_ray(list, o, d);
		if (a.t1 >= min && a.t1 <= 600000 && a.t1 < closer.clost)
		{
			closer.obj = list;
			closer.clost = a.t1;
		}
		if (a.t2 >= min && a.t2 <= 600000 && a.t2 < closer.clost)
		{
			closer.obj = list;
			closer.clost = a.t2;
		}
		list = list->next;
	}
	return (closer);
}

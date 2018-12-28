// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   light.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2018/10/26 13:18:55 by vkarpova          #+#    #+#             */
// /*   Updated: 2018/10/26 13:18:56 by vkarpova         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "RTv1.h"

double	ComputeLighting(t_all *all, t_vector N)
{
	double		i;
	double		NL;
	t_vector	L;
	t_light		*l;

	i = 0;
	l = (t_light *)(all->light->content);
	L = minus(l->pos, all->P);
	NL = dot(N, L);
	if (NL > 0)
		i += l->intense * NL / (dlinna(N) * dlinna(L));
	return (i);
}

t_vector	ReflectRay(t_vector M, t_vector N)
{
	t_vector	A;
	t_vector	B;
	t_vector	R;
	double		res;

	res = dot(N, M);
	A = times(res, N);
	B = times(2, A);
	R = minus(B, M);
	return (R);
}

int		ReflectedColor(t_list *list, t_all *all, double closest)
{
	// t_list	*list;
	t_list	*light;
	int		color;

	light = all->light;
	// list = all->obj;
	all->P = plus(all->cam, times(closest, all->view));
	while (light)
	{
		if (list)
		{
		if (list->content_size == CONE)
			color = light_cone((t_light *)(light->content), all, (t_cone *)(list->content));
		else if (list->content_size == CYL)
			color = light_cyl((t_light *)(light->content), all, (t_cylinder *)(list->content));
		else if (list->content_size == SPHERE)
			color = light_sphere((t_light *)(light->content), all, (t_sphere *)(list->content));
		else if (list->content_size == PLANE)
			color = light_plane((t_light *)(light->content), all, (t_plane *)(list->content));
		list = list->next;
		}
		light = light->next;
	}
	return (color);
}

double		calc_reflect(double reflect, t_vector N, t_all *all, t_light *light)
{
	t_vector	R;
	t_vector	V;
	int			RV;
	double		i;

	V = all->view;
	if (reflect != -1)
	{
		R = ReflectRay((minus(light->pos, all->P)), N);
		RV = dot(R, V);
		if (RV > 0)
			i += light->intense * pow(RV / (dlinna(R) * dlinna(V)), reflect);
	}
	return (i);
}

int		light_sphere(t_light *light, t_all *all, t_sphere *sphere)
{
	t_vector	N;
	int			local_color;
	double		r;
	t_vector	s_col;
	t_vector	l_col;

	N = minus(all->P, sphere->c);
	N = times(1 / dlinna(N), N);
	// printf("COLOR ?? = %d\n", sphere->color);
	s_col = int_to_rgb(sphere->color);
	l_col = times(ComputeLighting(all, N), s_col);
	r = calc_reflect(sphere->reflect, N, all, light);
	// if (r <= 0)
	// 	return (local_color);
	l_col = times((1 - r), l_col);
	local_color = rgb_to_int(l_col);
	return (local_color);
}

int		light_cyl(t_light *light, t_all *all, t_cylinder *cyl)
{
	t_vector	N;
	int			local_color;
	double		r;
	t_vector	s_col;
	t_vector	l_col;

	N = minus(all->P, cyl->c);
	N = times(1 / dlinna(N), N);
	s_col = int_to_rgb(cyl->color);
	l_col = times(ComputeLighting(all, N), s_col);
	r = calc_reflect(cyl->reflect, N, all, light);
	// if (r <= 0)
	// 	return (local_color);
	l_col = times((1 - r), l_col);
	local_color = rgb_to_int(l_col);
	return (local_color);
}

int		light_cone(t_light *light, t_all *all, t_cone *cone)
{
	t_vector	N;
	int			local_color;
	double		r;
	t_vector	s_col;
	t_vector	l_col;

	N = minus(all->P, cone->c);
	N = times(1 / dlinna(N), N);
	// if (dot(N, cone->v) > 0) // ОБРЕЗКА ВТОРОГО КОНУСА
	// {
		s_col = int_to_rgb(cone->color);
		l_col = times(ComputeLighting(all, N), s_col);
		r = calc_reflect(cone->reflect, N, all, light);
		// if (r <= 0)
		// 	return (local_color);
		l_col = times((1 - r), l_col);
		local_color = rgb_to_int(l_col);
	// }
	return (local_color);
}

int		light_plane(t_light *light, t_all *all, t_plane *plane)
{
	t_vector	N;
	int			local_color;
	double		r;
	t_vector	s_col;
	t_vector	l_col;

	N = minus(all->P, plane->c);
	N = times(1 / dlinna(N), N);
	s_col = int_to_rgb(plane->color);
	l_col = times(ComputeLighting(all, N), s_col);
	r = calc_reflect(plane->reflect, N, all, light);
	// if (r <= 0)
	// 	return (local_color);
	l_col = times((1 - r), l_col);
	local_color = rgb_to_int(l_col);
	return (local_color);
}
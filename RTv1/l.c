// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   light.c                                            :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2018/10/26 13:18:55 by vkarpova          #+#    #+#             */
// // /*   Updated: 2018/10/26 13:18:56 by vkarpova         ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

// #include "RTv1.h"

// double	ComputeLighting(t_all *all, t_vector N, double s)
// {
// 	double		i;
// 	double		NL;
// 	t_vector	L;
// 	t_vector	R;
// 	int			RV;
// 	t_light		*l;

// 	i = 0;
// 	l = (t_light *)(all->light->content);
// 	L = minus(l->pos, all->P);
// 	NL = dot(N, L);
// 	if (NL > 0)		//diffuse
// 		i += (l->intense * NL / (dlinna(N) * dlinna(L)));
// 	if (s != -1)
// 	{
// 		R = ReflectRay(L, N);		//specular
// 		RV = dot(R, all->view);
// 		if (RV > 0)
// 			i += l->intense * pow(RV / (dlinna(R) * dlinna(all->view)), s);
// 	}
// 	return (i);
// }

// double		calc_reflect(double reflect, t_vector N, t_all *all, t_light *light)
// {
// 	t_vector	R;
// 	t_vector	V;		// specular 
// 	int			RV;
// 	double		i;

// 	V = all->view;
// 	if (reflect > 0)
// 	{
// 		R = ReflectRay((minus(light->pos, all->P)), N);
// 		RV = dot(R, V);
// 		if (RV > 0)
// 			i += light->intense * pow(RV / (dlinna(R) * dlinna(V)), reflect);
// 	}
// 	return (i);
// }

// t_vector	ReflectRay(t_vector M, t_vector N)
// {
// 	t_vector	A;
// 	t_vector	B;
// 	t_vector	R;
// 	double		res;

// 	M = minus((t_vector){0, 0, 0}, M);
// 	res = dot(N, M);
// 	A = times(res, N);
// 	B = times(2, A);
// 	R = minus(B, M);
// 	return (R);
// }


// int		ReflectedColor(t_list *list, t_all *all, double closest)
// {
// 	t_list	*light;
// 	t_vector	L;
// 	int		color;

// 	if (all->light != NULL)
// 		light = all->light;
// 	else
// 		return (std_color(list));
// 	all->P = plus(all->cam, times(closest, all->view));
// 	while (light)
// 	{
// 		L = minus(((t_light *)(light->content))->pos, all->P);
// 		if (list->content_size == CONE)
// 			color = light_cone((t_light *)(light->content), all, (t_cone *)(list->content));
// 		else if (list->content_size == CYL)
// 			color = light_cyl((t_light *)(light->content), all, (t_cylinder *)(list->content));
// 		else if (list->content_size == SPHERE)
// 			color = light_sphere((t_light *)(light->content), all, (t_sphere *)(list->content));
// 		else if (list->content_size == PLANE)
// 			color = light_plane((t_light *)(light->content), all, (t_plane *)(list->content));
// 		light = light->next;
// 	}
// 	return (color);
// }

// int		light_sphere(t_light *light, t_all *all, t_sphere *sphere)
// {
// 	t_vector	N;
// 	int			local_color;
// 	double		r;
// 	t_vector	s_col;
// 	t_vector	l_col;

// 	N = minus(all->P, sphere->c);
// 	N = times((1 / dlinna(N)), N);
// 	s_col = int_to_rgb(sphere->color);
// 	l_col = times(ComputeLighting(all, N, sphere->reflect), s_col);
// 	// r = calc_reflect(sphere->reflect, N, all, light);
// 	r = sphere->reflect;
// 	if (r <= 0)
// 		return (rgb_to_int(l_col));
// 	l_col = times((1 - r), l_col);
// 	local_color = rgb_to_int(l_col);
// 	return (local_color);
// }

// int		light_cyl(t_light *light, t_all *all, t_cylinder *cyl)
// {
// 	t_vector	N;
// 	int			local_color;
// 	int			refl_color;
// 	double		r;
// 	// t_vector	s_col;
// 	t_vector	l_col;

// 	N = minus(all->P, cyl->c);
// 	N = times((1 / dlinna(N)), N);
// 	// s_col = int_to_rgb(cyl->color);
// 	// l_col = times(ComputeLighting(all, N, cyl->reflect), s_col);
// 	local_color = ComputeLighting(all, N, cyl->reflect) * cyl->color;
// 	// r = calc_reflect(cyl->reflect, N, all, light);
// 	r = cyl->reflect;
// 	if (r <= 0)
// 		return (local_color);
// 	l_col = ReflectRay(all->view, N);
// 	all->cam = all->P;
// 	all->view = l_col;
// 	refl_color = TraceRay(all);
// 	return (local_color * (1 - r) + refl_color*r);
// }

// int		light_cone(t_light *light, t_all *all, t_cone *cone)
// {
// 	t_vector	N;
// 	int			local_color;
// 	double		r;
// 	t_vector	s_col;
// 	t_vector	l_col;

// 	// local_color = FON;
// 	N = minus(all->P, cone->c);
// 	N = times((1 / dlinna(N)), N);
// 	// if (dot(N, cone->v) > 0) // ОБРЕЗКА ВТОРОГО КОНУСА
// 	// {
// 		s_col = int_to_rgb(cone->color);
// 		l_col = times(ComputeLighting(all, N, cone->reflect), s_col);
// 		// r = calc_reflect(cone->reflect, N, all, light);
// 		r = cone->reflect;
// 		if (r <= 0)
// 			return (rgb_to_int(l_col));
// 		l_col = times((1 - r), l_col);
// 		local_color = rgb_to_int(l_col);
// 	// }
// 	return (local_color);
// }

// int		light_plane(t_light *light, t_all *all, t_plane *plane)
// {
// 	t_vector	N;
// 	int			local_color;
// 	double		r;
// 	t_vector	s_col;
// 	t_vector	l_col;

// 	N = minus(all->P, plane->c);
// 	N = times((1 / dlinna(N)), N);
// 	s_col = int_to_rgb(plane->color);
// 	l_col = times(ComputeLighting(all, N, plane->reflect), s_col);
// 	// r = calc_reflect(plane->reflect, N, all, light);
// 	r = plane->reflect;
// 	if (r <= 0)
// 		return (rgb_to_int(l_col));
// 	l_col = times((1 - r), l_col);
// 	local_color = rgb_to_int(l_col);
// 	return (local_color);
// }
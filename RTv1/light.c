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

int		ReflectedColor(t_all *all, t_clos clos)
{
	t_list		*light;
	t_vector	k;
	t_clos 		shadow;

	light = all->light;
	all->N = minus(all->P, fig_center(clos.obj));
	all->N = times((1 / dlinna(all->N)), all->N);
	while (light)
	{
		all->L = minus(((t_light *)(light->content))->pos, all->P);
		shadow = closer_obj(all);
		if ((shadow.obj) != NULL)
		{
			k.x += diff(clos.obj, all, (t_light *)(light->content));
			if ((fig_specular(clos.obj)) > 0)
				k.y += spec(clos.obj, all, (t_light *)(light->content));
		}
		light = light->next;
	}
	return (color(k.x, k.y, clos));
}

double		diff(t_list *list, t_all *all, t_light *light)
{
	double		i;
	double		NL;

	i = 0;
	NL = dot(all->N, all->L);
	if (NL > 0)
		i = light->intense * NL / (dlinna(all->N) * dlinna(all->L));
	// printf("i = %f\n", i);
	return (i);
}

double		spec(t_list *list, t_all *all, t_light *light)
{
	t_vector	R;
	t_vector	V;
	int			RV;
	double		j;

	V = minus((t_vector){0, 0, 0}, all->view);
	j = 0;
	R = ReflectRay(all->L, all->N);
	RV = dot(R, V);
	if (RV > 0)
		j = light->intense * pow((RV / (dlinna(R) * dlinna(V))), fig_specular(list));
	// printf("j = %f\n", j);
	return (j);
}

t_vector	ReflectRay(t_vector N, t_vector L)
{
	t_vector	A;
	t_vector	B;
	t_vector	R;
	double		res;

	res = dot(N, L);
	A = times(res, N);
	B = times(2, A);
	R = minus(B, L);
	return (R);
}

int		color(double i, double j, t_clos clos)
{
	t_vector	color;

	color = int_to_rgb(fig_color(clos.obj));
	// printf("i = %f, j = %f, col = %d\n", i, j, fig_color(clos.obj));
	color.x += j * 20;
	color.y += j * 20;
	color.z += j * 20;
	
	// printf("1 = %f, %f, %f\n", color.x, color.y, color.z);
	if ((color.x *= i) > 255)
		color.x = 255;
	if ((color.y *= i) > 255)
		color.y = 255;
	if ((color.z *= i) > 255)
		color.z = 255;

	return (rgb_to_int(color));
}


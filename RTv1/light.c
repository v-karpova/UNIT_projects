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

int		ReflectedColor(t_all *all, t_clos clos, t_vec *vec)
{
	t_list		*light;
	t_vector	k;

	light = all->light;
	while (light)
	{
		vec->L = minus(((t_light *)(light->content))->pos, vec->P);
		// if ((closer_obj(all->obj, vec->P, vec->L, 0.01).obj) != NULL)
		// {
			k.x += diff(((t_light *)(light->content))->intense, vec);
			if ((fig_specular(clos.obj)) > 0)
				k.y += spec(fig_specular(clos.obj), ((t_light *)(light->content))->intense, vec);
		// }
		light = light->next;
	}
	return (color(k.x, k.y, clos));
}

double		diff(double intense, t_vec *vec)
{
	double		i;
	double		NL;

	i = 0;
	NL = dot(vec->N, vec->L);
	if (NL > 0)
		i = intense * NL / (dlinna(vec->N) * dlinna(vec->L));
	return (i);
}

double		spec(double spec, double intense, t_vec *vec)
{
	t_vector	R;
	double		RV;
	double		j;

	j = 0;
	// R = ReflectRay(vec->L, vec->N);
	R = minus(times(2 * dot(vec->N, vec->L), vec->N), vec->L);
	RV = dot(R, vec->V);
	if (RV > 0)
		j += intense * pow((RV / (dlinna(R) * dlinna(vec->V))), spec);
	return (j);
}

t_vector	ReflectRay(t_vector L, t_vector N)
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

	color.x += j * 255;
	color.y += j * 255;
	color.z += j * 255;

	color.x *= i;
	color.y *= i;
	color.z *= i;

	color = check_color(color);
	return (rgb_to_int(color));
}

t_vector	check_color(t_vector color)
{
	if (color.x > 255)
		color.x = 255;
	if (color.y > 255)
		color.y = 255;
	if (color.z > 255)
		color.z = 255;
	if (color.x < 0)
		color.x = 0;
	if (color.y < 0)
		color.y = 0;
	if (color.z < 0)
		color.z = 0;
	return (color);
}
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

double	ComputeLighting(t_all *all, t_vector P, t_vector N)
{
	double		i;
	double		NL;
	t_vector	L;

	i = 0;
	if (all->light.type == 0)   //общий свет
		i += all->light.intens;
	else
	{
		if (all->light.type == 1) 	// точечный свет
			L = minus(all->light.pos, P);
		else
			L = all->light.direction;
			NL = umnozh(N, L);
		if (NL > 0)
			i += all->light.intens * NL / (dlinna(N) * dlinna(L));
	}
	L = minus(all->light.pos, P);
	NL = umnozh(N, L);
	if (NL > 0)
		i += all->light.intens * NL / (dlinna(N) * dlinna(L));
	return (i);
}



t_vector	ReflectRay(t_vector M, t_vector N)
{
	t_vector	A;
	t_vector	B;
	t_vector	R;
	double		res;

	res = umnozh(N, M);
	A = times(res, N);
	B = times(2, A);
	R = minus(B, M);
	return (R);
}


int		ReflectedColor(t_all *all, double closest)
{
	t_vector	P;
	t_vector	N;
	t_vector	R;
	t_vector	O;
	int			local_color;
	double		reflected_color;
	double		r;
	t_vector	s_col;
	t_vector	l_col;
	int	res_col;

	P = times(closest, all->view);
	P = plus(all->cam, P);
	N = minus(P, all->sphere.c);
	N = times(1 / dlinna(N), N);


	s_col = int_to_rgb(all->sphere.color);
	l_col = times(ComputeLighting(all, P, N), s_col);
	

	// local_color = all->sphere.color * ComputeLighting(all, P, N);
	// return (local_color);

	r = all->sphere.reflect;
	if (/*depth <= 0 or */r <= 0)
		return (local_color);

	
	// // Compute the reflected color
	// O.x = 0;
	// O.y = 0;
	// O.z = 0;
	// R = minus(O, all->view);
	// R = ReflectRay(R, N);
	// // reflected_color = TraceRay(all);
	
	l_col = times((1 - r), l_col);
	local_color = rgb_to_int(l_col);
	return (local_color);
	// return (local_color * (1 - r)) + reflected_color * r);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:56:18 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/23 14:56:20 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector		minus(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return(new);
}

t_vector		plus(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	new.z = a.z + b.z;
	return(new);
}

t_vector		times(double n, t_vector a)
{
	t_vector	new;

	new.x = a.x * n;
	new.y = a.y * n;
	new.z = a.z * n;
	return(new);
}

double		umnozh(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	res.res = res.x + res.y + res.z;
	return(res.res);
}

t_vector		scal(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - b.y * a.z;
	res.y = a.z * b.x - b.z * a.x;
	res.z = a.x * b.y - b.x * a.y;
	return(res);
}

double		dlinna(t_vector a)
{
	t_vector	res;

	res.res = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return(res.res);
}

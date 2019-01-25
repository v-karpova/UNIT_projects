/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:34:37 by vkarpova          #+#    #+#             */
/*   Updated: 2018/11/14 14:34:38 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vector	IntersectRay(t_list *list, t_vector O, t_vector D)
{
	t_vector	a;

	if (list)
	{
		if (list->content_size == CONE)
			a = IntersectRayCone((t_cone *)(list->content), O, D);
		else if (list->content_size == CYL)
			a = IntersectRayCylinder((t_cylinder *)(list->content), O, D);
		else if (list->content_size == SPHERE)
			a = IntersectRaySphere((t_sphere *)(list->content), O, D);
		else if (list->content_size == PLANE)
			a = IntersectRayPlane((t_plane *)(list->content), O, D);
		else
		{
			a = (t_vector){600000, 600000, 600000};
		}
		
	}
	return (a);
}

t_vector		IntersectRaySphere(t_sphere *sphere, t_vector O, t_vector D)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	a = (t_vector){600000, 600000, 600000};
	OC = minus(O, sphere->c);
	k.x = dot(D, D);
	k.y = 2 * dot(OC, D);
	k.z = dot(OC, OC) - sphere->r * sphere->r;
	disc = k.y * k.y - 4 * k.x * k.z;
	if (disc < 0)
	{
		a.t1 = 600000;
		a.t2 = 600000;
		return (a);
	}
	a.t1 = (-k.y + sqrt(disc)) / (2 * k.x);
	a.t2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (a);
}


t_vector		IntersectRayCylinder(t_cylinder *cylinder, t_vector O, t_vector D)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	a = (t_vector){600000, 600000, 600000};
	// cylinder->v = norm(cylinder->v);
	// cylinder->v = times((1 / dlinna(cylinder->v)), cylinder->v);
	OC = minus(O, cylinder->c);
	k.x = dot(D, D) - dot(D, cylinder->v) * dot(D, cylinder->v);
	k.y = 2 * (dot(OC, D) - dot(cylinder->v, D) * dot(OC, cylinder->v));
	k.z = dot(OC, OC) - dot(OC, cylinder->v) * dot(OC, cylinder->v) - cylinder->r * cylinder->r;
	disc = k.y * k.y - 4 * k.x * k.z;
	if (disc < 0)
	{
		a.t1 = 600000;
		a.t2 = 600000;
		return (a);
	}
	a.t1 = (-k.y + sqrt(disc)) / (2 * k.x);
	a.t2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (a);
}

t_vector		IntersectRayCone(t_cone *cone, t_vector O, t_vector D)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	a = (t_vector){600000, 600000, 600000};
	// cone->v = norm(cone->v);
	// cone->v = times((1 / dlinna(cone->v)), cone->v);
	OC = minus(O, cone->c);
	k.x = dot(D, D) - (1 + (cone->a)*(cone->a)) * dot(D, cone->v) * dot(D, cone->v);
	k.y = 2 * (dot(D, OC) - (1 + (cone->a)*(cone->a)) * dot(D, cone->v) * dot(OC, cone->v));
	k.z = dot(OC, OC) - (1 + (cone->a)*(cone->a)) * dot(OC, cone->v) * dot(OC, cone->v);
	disc = k.y * k.y - 4 * k.x * k.z;
	if (disc < 0)
	{
		a.t1 = 600000;
		a.t2 = 600000;
		return (a);
	}
	a.t1 = (-k.y + sqrt(disc)) / (2 * k.x);
	a.t2 = (-k.y - sqrt(disc)) / (2 * k.x);
	return (a);
}


t_vector		IntersectRayPlane(t_plane *plane, t_vector O, t_vector D)
{
	t_vector	OC;
	t_vector	a;
	double		i;
	double		j;

	a = (t_vector){600000, 600000, 600000};
	// plane->v = norm(plane->v);
	// if (dot(D, plane->v) < 0)
	// 	plane->v = minus((t_vector){0, 0 , 0}, plane->v);

	OC = minus(plane->c, O);
	i = dot(OC, plane->v);
	j = dot(D, plane->v);
	if (j == 0 || ((i / j) < 0))
	{
		a.t1 = 600000;
		a.t2 = 600000;
		return (a);
	}
	a.t1 = i / j;
	a.t2 = i / j;
	return (a);
}


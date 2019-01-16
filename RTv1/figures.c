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

t_vector	IntersectRay(t_all *all, t_list *list)
{
	t_vector	a;

	if (list->content_size == CONE)
		a = IntersectRayCone(all, (t_cone *)(list->content));
	else if (list->content_size == CYL)
		a = IntersectRayCylinder(all, (t_cylinder *)(list->content));
	else if (list->content_size == SPHERE)
		a = IntersectRaySphere(all, (t_sphere *)(list->content));
	else if (list->content_size == PLANE)
		a = IntersectRayPlane(all, (t_plane *)(list->content));
	return (a);
}

t_vector		IntersectRaySphere(t_all *all, t_sphere *sphere)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	OC = minus(all->cam, sphere->c);
	k.x = dot(all->view, all->view);
	k.y = 2 * dot(OC, all->view);
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


t_vector		IntersectRayCylinder(t_all *all, t_cylinder *cylinder)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	cylinder->v = times((1 / dlinna(cylinder->v)), cylinder->v);
	OC = minus(all->cam, cylinder->c);
	k.x = dot(all->view, all->view) - dot(all->view, cylinder->v) * dot(all->view, cylinder->v);
	k.y = 2 * (dot(OC, all->view) - dot(cylinder->v, all->view) * dot(OC, cylinder->v));
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

t_vector		IntersectRayCone(t_all *all, t_cone *cone)
{
	t_vector	OC;
	t_vector	a;
	t_vector	k;
	double		disc;

	cone->v = times((1 / dlinna(cone->v)), cone->v);
	OC = minus(all->cam, cone->c);
	k.x = dot(all->view, all->view) - (1 + (cone->a)*(cone->a)) * dot(all->view, cone->v) * dot(all->view, cone->v);
	k.y = 2 * (dot(all->view, OC) - (1 + (cone->a)*(cone->a)) * dot(all->view, cone->v) * dot(OC, cone->v));
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


t_vector		IntersectRayPlane(t_all *all, t_plane *plane)
{
	t_vector	OC;
	t_vector	a;
	double		i;
	double		j;

	plane->v = times((1 / dlinna(plane->v)), plane->v);
	if (dot(all->view, plane->v) < 0)
		plane->v = minus((t_vector){0, 0 , 0}, plane->v);

	OC = minus(plane->c, all->cam);
	i = dot(OC, plane->v);
	j = dot(all->view, plane->v);
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


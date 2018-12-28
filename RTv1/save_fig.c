/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_fig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:48:17 by vkarpova          #+#    #+#             */
/*   Updated: 2018/11/02 18:48:18 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		save_light(t_all *all)
{
	t_list		*tmp;
	t_light		light;
	char		*line;

	if (save_intense(all, &(light.intense)) &&
		(save_pos(all, &(light.pos))))
	{
		tmp = ft_lstnew(&(light), sizeof(t_light));
		tmp->content_size = LIGHT;
		ft_lstadd(&(all->light), tmp);
		return (1);
	}
	ft_putendl("You miss some info for light");
	return (0);
}

int		save_plane(t_all *all, t_obj *obj)
{
	t_list		*tmp;
	t_plane		plane;
	
	if (save_color(all, &(plane.color)) &&
		(save_reflect(all, &(plane.reflect))) &&
		(save_normal(all, &(plane.v))) &&
		(save_center(all, &(plane.c))))
	{
		tmp = ft_lstnew(&(plane), sizeof(t_plane));
		tmp->content_size = PLANE;
		ft_lstadd(&(all->obj), tmp);
		return (1);
	}
	ft_putendl("You miss some info for plane");
	return (0);
}

int		save_cylinder(t_all *all, t_obj *obj)
{
	t_list		*tmp;
	t_cylinder	cylinder;
	
	if (save_color(all, &(cylinder.color)) &&
		(save_reflect(all, &(cylinder.reflect))) &&
		(save_radius(all, &(cylinder.r))) &&
		(save_normal(all, &(cylinder.v))) &&
		(save_center(all, &(cylinder.c))))
		{
		tmp = ft_lstnew(&(cylinder), sizeof(t_cylinder));
		tmp->content_size = CYL;
		ft_lstadd(&(all->obj), tmp);
		return (1);
	}
	ft_putendl("You miss some info for cylinder");
	return (0);
}

int		save_sphere(t_all *all, t_obj *obj)
{
	t_list		*tmp;
	t_sphere	sphere;

	if (save_color(all, &(sphere.color)) &&
		(save_reflect(all, &(sphere.reflect))) &&
		(save_radius(all, &(sphere.r))) &&
		(save_center(all, &(sphere.c))))
	{
		// printf("COLOR = %d\n", sphere.color);
		tmp = ft_lstnew(&sphere, sizeof(t_sphere));
		tmp->content_size = SPHERE;
		ft_lstadd(&(all->obj), tmp);
		return (1);
	}
	ft_putendl("You miss some info for sphere");
	return (0);
}

int		save_cone(t_all *all, t_obj *obj)
{
	t_list		*tmp;
	t_cone		cone;
	
	if (save_color(all, &(cone.color)) &&
		(save_reflect(all, &(cone.reflect))) &&
		(save_angle(all, &(cone.a))) &&
		(save_normal(all, &(cone.v))) &&
		(save_center(all, &(cone.c))))
	{
		tmp = ft_lstnew(&cone, sizeof(t_cone));
		tmp->content_size = CONE;
		ft_lstadd(&(all->obj), tmp);
		return (1);
	}
	ft_putendl("You miss some info for cone");
	return (0);
}


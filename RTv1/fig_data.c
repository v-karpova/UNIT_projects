/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:42:38 by vkarpova          #+#    #+#             */
/*   Updated: 2019/01/16 15:42:40 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

double		fig_specular(t_list *list)
{
	if (list->content_size == CONE)
		return(((t_cone *)(list->content))->reflect);
	else if (list->content_size == CYL)
		return(((t_cylinder *)(list->content))->reflect);
	else if (list->content_size == SPHERE)
		return(((t_sphere *)(list->content))->reflect);
	else if (list->content_size == PLANE)
		return(((t_plane *)(list->content))->reflect);
	return (0);
}

int		fig_color(t_list *list)
{
	if (list->content_size == CONE)
		return(((t_cone *)(list->content))->color);
	else if (list->content_size == CYL)
		return(((t_cylinder *)(list->content))->color);
	else if (list->content_size == SPHERE)
		return(((t_sphere *)(list->content))->color);
	else if (list->content_size == PLANE)
		return(((t_plane *)(list->content))->color);
	return (0);
}

t_vector	fig_center(t_list *list)
{
	if (list->content_size == CONE)
		return(((t_cone *)(list->content))->c);
	else if (list->content_size == CYL)
		return(((t_cylinder *)(list->content))->c);
	else if (list->content_size == SPHERE)
		return(((t_sphere *)(list->content))->c);
	else if (list->content_size == PLANE)
		return(((t_plane *)(list->content))->c);
	return ((t_vector){0, 0, 0});
}

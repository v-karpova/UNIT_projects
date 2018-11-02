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

void	save_plane(char *line, t_all *all)
{
	char		**tmp;

	if (ft_strncmp(line, " color:", 7) == 0)
		all->plane.color = rgb_to_int(save_color(line, all));
	if (ft_strncmp(line, " normal:", 8) == 0)
		all->plane.v = save_normal(line, all);
	if (ft_strncmp(line, " center:", 8) == 0)
		all->plane.c = save_center(line, all);
	if (ft_strncmp(line, " specular:", 10) == 0)
		all->plane.reflect = (double)ft_atoi(&line[10]);
}

void	save_cylinder(char *line, t_all *all)
{
	char		**tmp;

	if (ft_strncmp(line, " color:", 7) == 0)
		all->cylinder.color = rgb_to_int(save_color(line, all));
	if (ft_strncmp(line, " radius:", 8) == 0)
		all->cylinder.r = (double)ft_atoi(&line[8]);
	if (ft_strncmp(line, " normal:", 8) == 0)
		all->cylinder.v = save_normal(line, all);
	if (ft_strncmp(line, " center:", 8) == 0)
		all->cylinder.c = save_center(line, all);
	if (ft_strncmp(line, " specular:", 10) == 0)
		all->cylinder.reflect = (double)ft_atoi(&line[10]);
}

void	save_sphere(char *line, t_all *all)
{
	char		**tmp;

	if (ft_strncmp(line, " color:", 7) == 0)
		all->sphere.color = rgb_to_int(save_color(line, all));
	if (ft_strncmp(line, " radius:", 8) == 0)
		all->sphere.r = (double)ft_atoi(&line[8]);
	if (ft_strncmp(line, " center:", 8) == 0)
		all->sphere.c = save_center(line, all);
	if (ft_strncmp(line, " specular:", 10) == 0)
		all->sphere.reflect = (double)ft_atoi(&line[10]);
}

void	save_cone(char *line, t_all *all)
{
	char		**tmp;

	if (ft_strncmp(line, " color:", 7) == 0)
		all->cone.color = rgb_to_int(save_color(line, all));
	if (ft_strncmp(line, " angle:", 7) == 0)
		all->cone.a = (double)ft_atoi(&line[7]);
	if (ft_strncmp(line, " normal:", 8) == 0)
		all->cone.v = save_normal(line, all);
	if (ft_strncmp(line, " center:", 8) == 0)
		all->cone.c = save_center(line, all);
	if (ft_strncmp(line, " specular:", 10) == 0)
		all->cone.reflect = (double)ft_atoi(&line[10]);
}

// void	save_obj(char *line, t_all *all, int obj)
// {
// 	if (obj == 0)
// 		save_light(line, all);
// 	else if (obj == 1)
// 		save_plane(line, all);
// 	else if (obj == 2)
// 		save_cylinder(line, all);
// 	else if (obj == 3)
// 		save_cone(line, all);
// 	else if (obj == 4)
// 		save_sphere(line, all);
// }

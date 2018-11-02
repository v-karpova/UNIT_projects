/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:45:11 by vkarpova          #+#    #+#             */
/*   Updated: 2018/11/02 18:45:15 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	save_light(char *line, t_all *all)
{
	char	**tmp;

	if (ft_strncmp(line, " intense:", 9) == 0)
	{
		tmp = ft_strsplit(&line[9], ',');
		all->light.intense = (double)ft_atoi(tmp[0]) / 10;	//intense / 10
		free(tmp);
	}
	if (ft_strncmp(line, " position:", 10) == 0)
	{
		tmp = ft_strsplit(&line[9], ',');
		all->light.pos.x = (double)ft_atoi(tmp[0]);
		all->light.pos.y = (double)ft_atoi(tmp[1]);
		all->light.pos.z = (double)ft_atoi(tmp[2]);
		free(tmp);
	}
}

t_vector	save_color(char *line, t_all *all)
{
	t_vector	C;
	char		**tmp;

	tmp = ft_strsplit(&line[7], ',');
	C.x = (double)ft_atoi(tmp[0]);
	C.y = (double)ft_atoi(tmp[1]);
	C.z = (double)ft_atoi(tmp[2]);
	free(tmp);
	return (C);
}

t_vector	save_normal(char *line, t_all *all)
{
	t_vector	N;
	char		**tmp;

	tmp = ft_strsplit(&line[8], ',');
	N.x = (double)ft_atoi(tmp[0]);
	N.y = (double)ft_atoi(tmp[1]);
	N.z = (double)ft_atoi(tmp[2]);
	free(tmp);
	return (N);
}

t_vector	save_center(char *line, t_all *all)
{
	t_vector	C;
	char		**tmp;

	tmp = ft_strsplit(&line[8], ',');
	C.x = (double)ft_atoi(tmp[0]);
	C.y = (double)ft_atoi(tmp[1]);
	C.z = (double)ft_atoi(tmp[2]);
	free(tmp);
	return (C);
}

t_vector	save_cam(char *line, t_all *all)
{
	t_vector	C;
	char		**tmp;

	tmp = ft_strsplit(&line[7], ',');
	C.x = (double)ft_atoi(tmp[0]);
	C.y = (double)ft_atoi(tmp[1]);
	C.z = (double)ft_atoi(tmp[2]);
	free(tmp);
	return (C);
}

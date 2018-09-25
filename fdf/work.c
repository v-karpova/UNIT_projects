/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:38:51 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/20 18:38:52 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	*save_coords(char *line, int line_nb, t_all *all)
{
	t_matrix	*coords;
	char		**split;
	char		**split2;
	int			i;

	split = ft_strsplit(line, ' ');
	i = 0;
	coords = (t_matrix *)malloc(sizeof(t_matrix) * all->map_x);
	while (split[i] != '\0')
	{
		coords[i].x = i * BIGGER;
		coords[i].y = line_nb * BIGGER;
		coords[i].z = (double)ft_atoi_base(split[i], 10) * BIGGER;
		if (ft_strchr(split[i], ','))
		{
			split2 = ft_strsplit(split[i], ',');
			coords[i].color = ft_atoi_base(split2[1] + 2, 16);
			// ft_freearr(atoi);
		}
		else
			coords[i].color = 0xF00E8FF;
		i++;
	}
	return (coords);
}

void	move_to(t_all *all, int where)
{
	int		line;
	int		pos;

	find_center(all);
	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			if (where == -1)
			{
				all->matrix[line][pos].x -= (WIN_X / 2);
				all->matrix[line][pos].y -= (WIN_Y / 2);
			}
			else
			{
				all->matrix[line][pos].x += (WIN_X / 2);
				all->matrix[line][pos].y += (WIN_Y / 2);
			}
			pos++;
		}
		line++;
	}
}

void	find_center(t_all *all)
{
	int		line;
	int		pos;

	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
			pos++;
		line++;
	}
	all->center[0] = all->matrix[line - 1][pos - 1].x / 2;
	all->center[1] = all->matrix[line - 1][pos - 1].y / 2;
	all->center[2] = all->matrix[line - 1][pos - 1].z / 2;
}

void	move_to_center(t_all *all)
{
	int		line;
	int		pos;

	find_center(all);
	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			all->matrix[line][pos].x -= all->center[0] - WIN_X / 2; 
			all->matrix[line][pos].y -= all->center[1] - WIN_Y / 2; 
			pos++;
		}
		line++;
	}
}
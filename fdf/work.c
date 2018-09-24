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
	int		 i;

	split = ft_strsplit(line, ' ');
	i = 0;
	coords = (t_matrix *)malloc(sizeof(t_matrix) * all->map_x);
	while (split[i] != '\0')
	{
		coords[i].x = i * BIGGER;
		coords[i].y = line_nb * BIGGER;
		coords[i].z = atoi(split[i]) * BIGGER;
		// printf("(%d,%d,%d) ", coords[i].x, coords[i].y, coords[i].z);
		i++;
	}
	// printf("\n");
		
	return (coords);
}

void	zoom(t_all *all, int how)
{
	int	 line;
	int	 pos;

	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			if (how == -1)
			{
				all->matrix[line][pos].x *= 0.8; //ограничение!
				all->matrix[line][pos].y *= 0.8; 
				all->matrix[line][pos].z *= 0.8;
			}
			else
			{
				all->matrix[line][pos].x *= 1.2; 
				all->matrix[line][pos].y *= 1.2; 
				all->matrix[line][pos].z *= 1.2; 
			}
			pos++;
		}
		line++;
	}
}

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

void		make_free_m(t_matrix **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void		make_free(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void		move_to(t_all *all, int where)
{
	int		line;
	int		pos;

	find_center(all);
	line = -1;
	while (++line < MAX_Y)
	{
		pos = -1;
		while (++pos < MAX_X)
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
		}
	}
}

void		find_center(t_all *all)
{
	int		line;
	int		pos;

	line = -1;
	while (++line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
			pos++;
	}
	all->center[0] = all->matrix[line - 1][pos - 1].x / 2;
	all->center[1] = all->matrix[line - 1][pos - 1].y / 2;
	all->center[2] = all->matrix[line - 1][pos - 1].z / 2;
}

void		move_to_center(t_all *all)
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

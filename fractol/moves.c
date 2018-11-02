/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 18:44:34 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/26 18:44:36 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_all *all, int where)
{
	int		line;
	int		pos;

	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			if (where == 1)
				all->matrix[line][pos].x += 10;
			else if (where == -1)
				all->matrix[line][pos].x -= 10;
			else if (where == 2)
				all->matrix[line][pos].y -= 10;
			else if (where == -2)
				all->matrix[line][pos].y += 10;
			pos++;
		}
		line++;
	}
}

void	rotat_x(t_all *all, double angle)
{
	int		line;
	int		pos;
	double	y;

	move_to(all, -1);
	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			y = all->matrix[line][pos].y;
			all->matrix[line][pos].y = y * cos(angle) +
										all->matrix[line][pos].z * sin(angle);
			all->matrix[line][pos].z = -y * sin(angle) +
										all->matrix[line][pos].z * cos(angle);
			pos++;
		}
		line++;
	}
	move_to(all, 1);
}

void	rotat_y(t_all *all, double angle)
{
	int		line;
	int		pos;
	double	x;

	move_to(all, -1);
	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			x = all->matrix[line][pos].x;
			all->matrix[line][pos].x = x * cos(angle) +
										all->matrix[line][pos].z * sin(angle);
			all->matrix[line][pos].z = -x * sin(angle) +
										all->matrix[line][pos].z * cos(angle);
			pos++;
		}
		line++;
	}
	move_to(all, 1);
}

void	rotat_z(t_all *all, double angle)
{
	int		line;
	int		pos;
	double	x;

	move_to(all, -1);
	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			x = all->matrix[line][pos].x;
			all->matrix[line][pos].x = x * cos(angle) +
										all->matrix[line][pos].y * sin(angle);
			all->matrix[line][pos].y = -x * sin(angle) +
										all->matrix[line][pos].y * cos(angle);
			pos++;
		}
		line++;
	}
	move_to(all, 1);
}

void	zoom(t_all *all, int how)
{
	int		line;
	int		pos;

	move_to(all, -1);
	line = -1;
	while (++line < MAX_Y)
	{
		pos = -1;
		while (++pos < MAX_X)
		{
			if (how == -1)
			{
				all->matrix[line][pos].x = all->matrix[line][pos].x * 0.8;
				all->matrix[line][pos].y = all->matrix[line][pos].y * 0.8;
				all->matrix[line][pos].z = all->matrix[line][pos].z * 0.8;
			}
			else
			{
				all->matrix[line][pos].x = all->matrix[line][pos].x * 1.2;
				all->matrix[line][pos].y = all->matrix[line][pos].y * 1.2;
				all->matrix[line][pos].z = all->matrix[line][pos].z * 1.2;
			}
		}
	}
	move_to(all, 1);
}

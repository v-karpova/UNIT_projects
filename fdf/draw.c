/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:38:36 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/20 18:38:40 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print(t_matrix **matrix, int max_x, int max_y)
{
	int		line;
	int		pos;

	line = 0;
	while (line < max_y)
	{
		pos = 0;
		while (pos < max_x)
		{
			printf("(%f,%f,%f) ", matrix[line][pos].x, matrix[line][pos].y,matrix[line][pos].z);
			pos++;
		}
		printf("\n");
		line++;
	}
}

void	move_to_center(t_all *all)
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

void	go(t_all *all)
{
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "FDF vkarpova");
	move_to_center(all);
	draw(all);
	mlx_hook(WIN_PTR, 2, 5, event, all);
	mlx_loop(MLX_PTR);
}

void	draw(t_all *all)
{
	int		line;
	int		pos;

	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X - 1)
		{
			make_line(all, &all->matrix[line][pos], &all->matrix[line][pos + 1]);
			pos++;
		}
		line++;
	}
	line = 0;
	while (line < MAX_Y - 1)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			make_line(all, &all->matrix[line][pos], &all->matrix[line + 1][pos]);
			pos++;
		}
		line++;
	}

}

void	make_line(t_all *all, t_matrix *c1, t_matrix *c2)
{
	int		xy[2];

	xy[0] = c1->x;
	xy[1] = c1->y;
	if (fabs(c2->y - c1->y) > fabs(c2->x - c1->x))
		while (c1->y > c2->y ? xy[1] >= c2->y : xy[1] <= c2->y)
		{
			xy[0] = ((xy[1] - c1->y) / (c1->y - c2->y) * (c1->x - c2->x) + c1->x);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], 0x00FFFFFF);
			c2->y > c1->y ? xy[1]++ : xy[1]--;
		}
	else
		while (c1->x > c2->x ? xy[0] >= c2->x : xy[0] <= c2->x)
		{
			xy[1] = ((xy[0] - c1->x) / (c1->x - c2->x) * (c1->y - c2->y) + c1->y);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], 0x00FFFFFF);
			c2->x > c1->x ? xy[0]++ : xy[0]--;
		}
}

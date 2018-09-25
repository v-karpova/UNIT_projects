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

void	color_move(t_all *all, int how)
{
	int		line;
	int		pos;

	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			if (how == 1)
				all->matrix[line][pos].color += 0x010105;
			else
				all->matrix[line][pos].color -= 0x010105;
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
	mlx_hook(WIN_PTR, 2, 5, event1, all);
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
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], c1->color);
			c2->y > c1->y ? xy[1]++ : xy[1]--;
		}
	else
		while (c1->x > c2->x ? xy[0] >= c2->x : xy[0] <= c2->x)
		{
			xy[1] = ((xy[0] - c1->x) / (c1->x - c2->x) * (c1->y - c2->y) + c1->y);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], c1->color);
			c2->x > c1->x ? xy[0]++ : xy[0]--;
		}
}

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

	line = -1;
	while (++line < MAX_Y)
	{
		pos = -1;
		while (++pos < MAX_X)
		{
			if (how == 1)
				all->matrix[line][pos].color += 0x010110;
			else
				all->matrix[line][pos].color -= 0x010110;
		}
	}
}

void	note(t_all *all)
{
	mlx_string_put(MLX_PTR, WIN_PTR, 20, 20, 0xFFFFFFF, "SOME NOTES :)");
	mlx_string_put(MLX_PTR, WIN_PTR, 20, 45,
					0xFFFFFFF, "- shift by LEFT/RIGHT/UP/DOWN keys");
	mlx_string_put(MLX_PTR, WIN_PTR, 20, 70, 0xFFFFFFF, "- rotations :");
	mlx_string_put(MLX_PTR, WIN_PTR, 35, 95,
					0xFFFFFFF, "press mouse left button and move");
	mlx_string_put(MLX_PTR, WIN_PTR, 35, 115,
					0xFFFFFFF, "(x axis) by 1/2 keys");
	mlx_string_put(MLX_PTR, WIN_PTR, 35, 135,
					0xFFFFFFF, "(y axis) by 3/4 keys");
	mlx_string_put(MLX_PTR, WIN_PTR, 35, 155,
					0xFFFFFFF, "(z axis) by 5/6 keys");
	mlx_string_put(MLX_PTR, WIN_PTR, 20, 180,
					0xFFFFFFF, "- zoom by Q/E keys or mouse scroll up/down");
	mlx_string_put(MLX_PTR, WIN_PTR, 20, 205, 0xFFFFFFF,
					"- color change by C/V keys or right mouse button");
	mlx_string_put(MLX_PTR, WIN_PTR, 20, 230,
					0xFFFFFFF, "- close all by ESC/(X) key/button");
}

void	go(t_all *all)
{
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "FDF vkarpova");
	note(all);
	move_to_center(all);
	draw(all);
	mlx_hook(WIN_PTR, 2, 5, event1, all);
	mlx_hook(WIN_PTR, 4, 1L << 2, mouse_press, all);
	mlx_hook(WIN_PTR, 5, 1L << 3, mouse_release, all);
	mlx_hook(WIN_PTR, 6, 1L << 13, mouse_move, all);
	mlx_hook(WIN_PTR, 17, 1L << 17, x_close, all);
	mlx_loop(MLX_PTR);
}

void	draw(t_all *all)
{
	int		line;
	int		pos;

	note(all);
	line = -1;
	if (MAX_Y == 1 && MAX_X == 1)
		mlx_pixel_put(MLX_PTR, WIN_PTR, all->matrix[0][0].x,
						all->matrix[0][0].y, all->matrix[0][0].color);
	while (++line < MAX_Y)
	{
		pos = -1;
		while (++pos < MAX_X - 1)
			make_line(all, &all->matrix[line][pos],
						&all->matrix[line][pos + 1]);
	}
	line = -1;
	while (++line < MAX_Y - 1)
	{
		pos = -1;
		while (++pos < MAX_X)
			make_line(all, &all->matrix[line][pos],
						&all->matrix[line + 1][pos]);
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
			xy[0] = ((xy[1] - c1->y) / (c1->y - c2->y) *
					(c1->x - c2->x) + c1->x);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], c1->color);
			c2->y > c1->y ? xy[1]++ : xy[1]--;
		}
	else
		while (c1->x > c2->x ? xy[0] >= c2->x : xy[0] <= c2->x)
		{
			xy[1] = ((xy[0] - c1->x) / (c1->x - c2->x) *
					(c1->y - c2->y) + c1->y);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], c1->color);
			c2->x > c1->x ? xy[0]++ : xy[0]--;
		}
}

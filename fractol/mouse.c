/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 19:09:42 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/16 19:09:43 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int button, int x, int y, t_all *all)
{
	mlx_destroy_image(MLX_PTR, IMG_PTR);
	IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	if (button == 2)
	{
		all->mouse.press = 1;
		event(8, all);
	}
	if (button == 4)
	{
		// event(69, all);
		ZOOM *= 1.1;
		X += (1.5 * (x - WIN_X / 2) / (0.5 * ZOOM * WIN_X) + MV_X) / ZOOM;
		Y += (1.5 * (y - WIN_Y / 2) / (0.5 * ZOOM * WIN_Y) + MV_Y) / ZOOM;
		now_do(all, all->fract);
	}
	if (button == 5)
	{
		// event(78, all);
		ZOOM *= 0.9;
		X -= (1.5 * (x - WIN_X / 2) / (0.5 * ZOOM * WIN_X) + MV_X) / ZOOM;
		Y -= (1.5 * (y - WIN_Y / 2) / (0.5 * ZOOM * WIN_Y) + MV_Y) / ZOOM;
		now_do(all, all->fract);
	}
	if (button == 1)
	{
		all->mouse.press = 1;
		event(49, all);
		now_do(all, all->fract);
	}
	x = y;
	return (0);
}

int		mouse_release(int button, int x, int y, t_all *all)
{
	if (button == 1 || button == 2)
		all->mouse.press = 0;
	x = 0;
	y = 0;
	return (0);
}

int		mouse_move(int x, int y, t_all *all)
{
	if (all->stop == 0)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->mouse_y = (1.5 * (y - IMG_H / 2) / (0.5 * ZOOM * IMG_H) + MV_Y);
		all->mouse_x = (1.5 * (x - IMG_W / 2) / (0.5 * ZOOM * IMG_W) + MV_X);
		now_do(all, all->fract);
	}
	return (0);
}

int		x_close(t_all *all)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	free(all);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:35:08 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/01 18:35:23 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			event(int key, t_all *all)
{
	if (key == 53)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		// make_free_m(all->matrix);
		free(all);
		exit(0);
	}
	else if (key ==  126)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		MV_Y += (0.4 / ZOOM);
		now_do(all, all->fract);
	}
	else if (key == 125)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		MV_Y -= (0.4 / ZOOM);
		now_do(all, all->fract);
	}
	else if (key == 123)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		MV_X += (0.4 / ZOOM);
		now_do(all, all->fract);
	}
	else if (key == 124)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		MV_X -= (0.4 / ZOOM);
		now_do(all, all->fract);
	}
	else if (key == 78)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		ZOOM *= 0.9;
		now_do(all, all->fract);
	}
	else if (key == 69)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		ZOOM *= 1.1;
		now_do(all, all->fract);
	}
	else if (key == 8)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		COLOR += 1000;
		now_do(all, all->fract);
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	return (0);
}

int		mouse_press(int button, int x, int y, t_all *all)
{
	if (button == 2)
		event(8, all);
	if (button == 4)
		event(69, all);
	if (button == 5)
		event(78, all);
	if (button == 1)
		all->mouse.press = 1;
	
	x = y;
	return (0);
}

int		mouse_release(int button, int x, int y, t_all *all)
{
	if (button == 1)
		all->mouse.press = 0;
	// MV_X += all->mouse.x / 200;
	// MV_Y += all->mouse.y / 200;
	x = y;
	return (0);
}

int		mouse_move(int x, int y, t_all *all)
{
	double		save_x;
	double		save_y;

	save_x = all->mouse.x;
	save_y = all->mouse.y;
	// mlx_clear_window(MLX_PTR, WIN_PTR);
	// if (all->mouse.y > save_x)
		// CH_Y += 1;
	// if (all->mouse.x > save_x)
	// 	CH_X += 0.5;

	now_do(all, all->fract);
	all->mouse.x = 0;
	all->mouse.y = 0;
	return (0);
}

int		x_close(t_all *all)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	free(all);
	exit(0);
	return (0);
}

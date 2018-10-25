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
	mlx_destroy_image(MLX_PTR, IMG_PTR);
	IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	if (key == 53)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		free(all);
		exit(0);
	}
	else if (key == 18)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 1;
		now_do(all, all->fract);
	}
	else if (key == 19)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 2;
		now_do(all, all->fract);
	}
	else
		event1(key, all);
	return (0);
}

void		event1(int key, t_all *all)
{
	if (key == 20)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 3;
		now_do(all, all->fract);
	}
	else if (key == 21)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 4;
		now_do(all, all->fract);
	}
	else if (key == 23)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 5;
		now_do(all, all->fract);
	}
	else if (key == 49)
		all->stop = 1;
	else if (key == 36)
		all->stop = 0;
	else
		event2(key, all);
}

void		event2(int key, t_all *all)
{
	if (key == 26)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 7;
		now_do(all, all->fract);
	}
	else if (key == 28)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 8;
		now_do(all, all->fract);
	}
	else if (key == 126)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		MV_Y += (0.4 / ZOOM);
		now_do(all, all->fract);
	}
	else
		event3(key, all);
}

void		event3(int key, t_all *all)
{
	if (key == 125)
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
	else
		event4(key, all);
}

void		event4(int key, t_all *all)
{
	if (key == 78)
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
		COLOR += 1100;
		now_do(all, all->fract);
	}
	else if (key == 22)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		all->fract = 6;
		now_do(all, all->fract);
	}
}

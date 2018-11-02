/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:39:00 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/20 18:39:01 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			event1(int key, t_all *all)
{
	if (key == 12)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		zoom(all, -1);
		draw(all);
	}
	else if (key == 14)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		zoom(all, 1);
		draw(all);
	}
	else if (key == 18)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotat_x(all, 0.1);
		draw(all);
	}
	else
		event2(key, all);
	return (0);
}

void		event2(int key, t_all *all)
{
	if (key == 20)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotat_y(all, 0.1);
		draw(all);
	}
	else if (key == 21)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotat_y(all, -0.1);
		draw(all);
	}
	else if (key == 22)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotat_z(all, 0.1);
		draw(all);
	}
	else
		event3(key, all);
}

void		event3(int key, t_all *all)
{
	if (key == 123)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		move(all, -1);
		draw(all);
	}
	else if (key == 124)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		move(all, 1);
		draw(all);
	}
	else if (key == 126)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		move(all, 2);
		draw(all);
	}
	else
		event4(key, all);
}

void		event4(int key, t_all *all)
{
	if (key == 53)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		free(all);
		exit(0);
	}
	else if (key == 9)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		color_move(all, 1);
		draw(all);
	}
	else if (key == 23)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotat_z(all, -0.1);
		draw(all);
	}
	else
		event5(key, all);
}

void		event5(int key, t_all *all)
{
	if (key == 125)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		move(all, -2);
		draw(all);
	}
	else if (key == 8)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		color_move(all, -1);
		draw(all);
	}
	else if (key == 19)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		rotat_x(all, -0.1);
		draw(all);
	}
}

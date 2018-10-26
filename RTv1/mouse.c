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

#include "RTv1.h"

int		mouse_press(int button, int x, int y, t_all *all)
{
	// mlx_destroy_image(MLX_PTR, IMG_PTR);
	// IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	mlx_clear_window(MLX_PTR, WIN_PTR);
	if (button == 2)
	{
		all->mouse.press = 1;
		all->sphere.color += 0x010110;
		sphere(all);
	}
	if (button == 4)
	{
		all->sphere.r += 1;
		sphere(all);
	}
	if (button == 5)
	{
		all->sphere.r -= 1;
		sphere(all);
	}
	if (button == 1)
	{
		all->mouse.press = 1;
		sphere(all);
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
	mlx_clear_window(MLX_PTR, WIN_PTR);
	all->light.pos.x -= (x / 100);
	all->light.pos.y -= (y / 100);
	all->light.pos.z -= 5;
	sphere(all);
	return (0);
}

int		x_close(t_all *all)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	free(all);
	exit(0);
	return (0);
}

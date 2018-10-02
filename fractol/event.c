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

	return (0);
}

int		mouse_press(int button, int x, int y, t_all *all)
{
	// if (button == 2)
	// 	event4(9, all);
	// else if (button == 4)
	// 	event1(14, all);
	// else if (button == 5)
	// 	event1(12, all);
	if (button == 1)
		all->mouse.press = 1;
	x = y;
	return (0);
}

int		mouse_release(int button, int x, int y, t_all *all)
{
	if (button == 1)
		all->mouse.press = 0;
	x = y;
	return (0);
}

int		mouse_move(int x, int y, t_all *all)
{
	if (all->mouse.press == 1)
		all->mouse.press = 2;
	else if (all->mouse.press == 2)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		// rotat_x(all, (double)(all->mouse.x - x) / 200);
		// rotat_y(all, (double)(all->mouse.y - y) / 200);
		// draw(all);
	}
	all->mouse.x = x;
	all->mouse.y = y;
	return (0);
}

int		x_close(t_all *all)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);
	free(all);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   CRated: 2018/10/01 17:59:26 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/01 17:59:43 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put_img(t_all *all, int x, int y, int color)
{
	if (x < WIN_X || y < WIN_Y)
	{
		color = mlx_get_color_value(all->mlx_ptr, color);
		ft_memcpy(all->img + 4 * WIN_X * y + x * 4, &color, sizeof(int));
	}
}

void	now_do(t_all *all, int n)
{
	// if (n == 1)
	// 	mandelbrot_thread(all);
	if (n == 2)
		julia_thread(all);
	// else if (n == 3)
	//  	forever_thread(all);
	// else if (n == 4)
	//  	rabbit_thread(all);
	// else if (n == 5)
	//  	heart_thread(all);
	// else if (n == 6)
	//  	tricorn_thread(all);
	// else if (n == 7)
	//  	mandelbar_thread(all);
	// else if (n == 8)
	//  	snowflake_thread(all);
}

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

// void	note(t_all *all)
// {
// 	mlx_string_put(MLX_PTR, WIN_PTR, 20, 20, 0xFFFFFFF, "SOME NOTES :)");
	// mlx_string_put(MLX_PTR, WIN_PTR, 20, 45,
	// 				0xFFFFFFF, "- shift by LEFT/RIGHT/UP/DOWN keys");
	// mlx_string_put(MLX_PTR, WIN_PTR, 20, 70, 0xFFFFFFF, "- rotations :");
	// mlx_string_put(MLX_PTR, WIN_PTR, 35, 95,
	// 				0xFFFFFFF, "press mouse left button and move");
	// mlx_string_put(MLX_PTR, WIN_PTR, 35, 115,
	// 				0xFFFFFFF, "(x axis) by 1/2 keys");
	// mlx_string_put(MLX_PTR, WIN_PTR, 35, 135,
	// 				0xFFFFFFF, "(y axis) by 3/4 keys");
	// mlx_string_put(MLX_PTR, WIN_PTR, 35, 155,
	// 				0xFFFFFFF, "(z axis) by 5/6 keys");
	// mlx_string_put(MLX_PTR, WIN_PTR, 20, 180,
	// 				0xFFFFFFF, "- zoom by Q/E keys or mouse scroll up/down");
	// mlx_string_put(MLX_PTR, WIN_PTR, 20, 205, 0xFFFFFFF,
	// 				"- color change by C/V keys or right mouse button");
	// mlx_string_put(MLX_PTR, WIN_PTR, 20, 230,
	// 				0xFFFFFFF, "- close all by ESC/(X) key/button");
// }

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
	if (n == 1)
		mandelbrot_thread(all);
	if (n == 2)
		julia_thread(all);
	else if (n == 3)
	 	forever_thread(all);
	else if (n == 4)
	 	rabbit_thread(all);
	else if (n == 5)
	 	heart_thread(all);
	else if (n == 6)
	 	tricorn_thread(all);
	else if (n == 7)
	 	mandelbar_thread(all);
	else if (n == 8)
	 	snowflake_thread(all);
}

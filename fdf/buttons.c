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

int		event(int key, t_all *all)
{
		
		if (key == 53)         // ECS
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			free(all);
			exit(0);
		}
		else if (key == 12)		 // Q zoom--
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			zoom(all, -1);
			draw(all);

		}
		else if (key == 14)		 // E zoom++
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			zoom(all, 1);
			draw(all);
		}
		else if (key == 123)		 // <- left
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			move(all, -1);
			draw(all);
		}
		else if (key == 124)		 // -> right
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			move(all, 1);
			draw(all);
		}
		else if (key == 126)		 // up move
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			move(all, 2);
			draw(all);
		}
		else if (key == 125)		 // down move
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			move(all, -2);
			draw(all);
		}
		else if (key == 18)		 //  1 - rot x 1
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			rotat_x(all, 1);
			draw(all);
		}
		else if (key == 19)		 //  2 - rot x  -1
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			rotat_x(all, -1);
			draw(all);
		}
		else if (key == 20)		 // 3 - rot y 1
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			rotat_y(all, 1);
			draw(all);
		}
		else if (key == 21)		 //  4 - rot y -1
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			rotat_y(all, -1);
			draw(all);
		}
		else if (key == 22)		 // 5 - rot z 1
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			rotat_z(all, 1);
			draw(all);
		}
		else if (key == 23)		 //  6 - rot z -1
		{
			mlx_clear_window(MLX_PTR, WIN_PTR);
			rotat_z(all, -1);
			draw(all);
		}
		// else if (key == 23)		 //  R - reset ?????
		// {
		// 	mlx_clear_window(MLX_PTR, WIN_PTR);
		
		// 	draw(all);
		// }







		return (0);
}


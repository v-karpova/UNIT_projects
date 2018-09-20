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
		mlx_clear_window(MLX_PTR, WIN_PTR);
		if (key == 53)         // ECS
		{
			free(all);
			exit(0);
		}
		else if (key == 12)		 // Q zoom--
		{
			zoom(all, -1);
			draw(all);
		}
		else if (key == 14)		 // E zoom++
		{
			zoom(all, 1);
			draw(all);
		}
		else if (key == 123)		 // <- left
		{
			move(all, -1);
			draw(all);
		}
		else if (key == 124)		 // -> right
		{
			move(all, 1);
			draw(all);
		}
		else if (key == 126)		 // up move
		{
			move(all, 2);
			draw(all);
			}
		else if (key == 125)		 // down move
		{
			move(all, -2);
			draw(all);
		}
		// 		else if (key == )		 // 
		// {
		// 	mlx_clear_window(MLX_PTR, WIN_PTR);
			
		// 	draw(all);
		// }
		// 		else if (key == )		 // 
		// {
		// 	mlx_clear_window(MLX_PTR, WIN_PTR);
			
		// 	draw(all);
		// }
		// 		else if (key == )		 // 
		// {
		// 	mlx_clear_window(MLX_PTR, WIN_PTR);
			
		// 	draw(all);
		// }
		// 		else if (key == )		 // 
		// {
		// 	mlx_clear_window(MLX_PTR, WIN_PTR);
			
		// 	draw(all);
		// }
		return (0);
}


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

void	mandelbrot(t_all *all)
{
	int		y;
	int		x;
	int		n;

	y = -1;
	while (++y < IMAGE_H)
	{
		CI = MAX_I - y * I_FACTOR; 
		// CI = (y - IMAGE_H / 2) / (0.5 * IMAGE_H);
		x = -1;
		while (++x < IMAGE_W)
		{
			CR = MIN_R + x * R_FACTOR;
			// CR = 1.5 * (x - IMAGE_W / 2) / (0.5 * IMAGE_W);
			ZR = CR;
			ZI = CI;
			INSIDE = 1;
			n = -1;
			while (++n < MAX_ITER)
			{
				ZR2 = ZR * ZR;
				ZI2 = ZI * ZI;
				if (ZR2 + ZI2 > 4)
				{
					INSIDE = 0;
					break;
				}
				ZI = 2 * ZR * ZI + CI;
				ZR = ZR2 - ZI2 + CR;
			}
			if (INSIDE == 1)
				mlx_pixel_put(MLX_PTR, WIN_PTR, x, y, 0xFFF0000);
		}
	}
}

void	julia(t_all *all)
{
	int		y;
	int		x;
	int		n;
	
	y = -1;
	while (++y < IMAGE_H)
	{
		CI = (y - IMAGE_H / 2) / (0.5 * IMAGE_H);
		x = -1;
		while (++x < IMAGE_W)
		{
			CR = 1.5 * (x - IMAGE_W / 2) / (0.5 * IMAGE_W);
			ZR = CR;
			ZI = CI;
			INSIDE = 1;
			n = -1;
			while (++n < MAX_ITER)
			{
				ZR2 = ZR * ZR;
				ZI2 = ZI * ZI;
				if (ZR2 + ZI2 > 4)
				{
					INSIDE = 0;
					break;
				}
				ZI = 2 * ZR * ZI + CI_J;
				ZR = ZR2 - ZI2 + CR_J;
			}
			if (INSIDE == 1)
				mlx_pixel_put(MLX_PTR, WIN_PTR, x, y, 0xFFF0000);
		}
	}
}

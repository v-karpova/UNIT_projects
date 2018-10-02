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

void	pixel_put_img(t_all *win, int x, int y, int colour)
{
	if (x < WIN_X || y < WIN_Y)
	{
		colour = mlx_get_color_value(win->mlx_ptr, colour);
		ft_memcpy(win->img + 4 * WIN_X * y + x * 4, &colour, sizeof(int));
	}
}

void	mandelbrot(t_all *all)
{
	int		n;

	all->y = -1;
	while (++all->y < IMAGE_H)
	{
		//CI = MAX_I - all->y * I_FACTOR; 
		CI = (all->y - IMAGE_H / 2) / (0.5 * IMAGE_H);
		all->x = -1;
		while (++all->x < IMAGE_W)
		{
			//CR = MIN_R + all->x * R_FACTOR;
			CR = 1.5 * (all->x - IMAGE_W / 2) / (0.5 * IMAGE_W);
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
				pixel_put_img(all, all->x, all->y, 0xFFF0000);//all->colour * i);
		}
	}
}

void	julia(t_all *all)
{
	int		n;
	
	all->y = -1;
	while (++all->y < IMAGE_H)
	{
		CI = (all->y - IMAGE_H / 2) / (0.5 * IMAGE_H);
		all->x = -1;
		while (++all->x < IMAGE_W)
		{
			CR = 1.5 * (all->x - IMAGE_W / 2) / (0.5 * IMAGE_W);
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
				pixel_put_img(all, all->x, all->y, 0xFFF0000);//all->colour * i);
		}
	}
}

void	THIRD(t_all *all)
{
	int		n;
	
	all->y = -1;
	while (++all->y < IMAGE_H)
	{
		CI = (all->y - IMAGE_H / 2) / (0.5 * IMAGE_H);
		all->x = -1;
		while (++all->x < IMAGE_W)
		{
			CR = 1.5 * (all->x - IMAGE_W / 2) / (0.5 * IMAGE_W);
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
				ZI = 2 * ZR * ZI;
				ZR = ZR2 - ZI2 - 1;
			}
			if (INSIDE == 1)
				pixel_put_img(all, all->x, all->y, 0xFFF0000);//all->colour * i);
		}
	}
}

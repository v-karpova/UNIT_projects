/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:32:32 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/03 20:32:33 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorn(t_all *all)
{
	int		n;
	
	all->y = -1;
	while (++all->y < IMG_H)
	{
		CI = 1.5 * (all->y - IMG_H / 2) / (0.5 * ZOOM * IMG_H) + MV_Y;
		all->x = -1;
		while (++all->x < IMG_W)
		{
			CR = 1.5 * (all->x - IMG_W / 2) / (0.5 * ZOOM * IMG_W) + MV_X;
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
				ZI = -2 * ZR * ZI + CI;
				ZR = ZR2 - ZI2 + CR;
			}
			if (INSIDE == 1)
				pixel_put_img(all, all->x, all->y, 0xFFF0000);
			else
				pixel_put_img(all, all->x, all->y, 0);
		}
	}
}

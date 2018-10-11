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

void	tricorn_thread(t_thread *p)
{
	t_thread	thread[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		thread[i].a = p->a;
		thread[i].n = i;
		pthread_create(&thread[i].p, NULL, tricorn, &thread[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(thread[i].p, NULL);
	// mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

void	*tricorn(void *v)
{
	t_thread	*p;
	int		n;
	
	p = (t_thread *)v;
	Y = -1;
	while (++Y < IMG_H)
	{
		CI = 1.5 * (Y - IMG_H / 2) / (0.5 * ZOOM * IMG_H) + MV_Y;
		X = -1;
		while (++X < IMG_W)
		{
			CR = 1.5 * (X - IMG_W / 2) / (0.5 * ZOOM * IMG_W) + MV_X;
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
				ZI = -2 * ZR * ZI + CI + JI;
				ZR = ZR2 - ZI2 + CR + JR;
			}
			if (INSIDE == 1)
				pixel_put_img(p, X, Y, COLOR * n);
			else
				pixel_put_img(p, X, Y, 0);
		}
	}
	return (p);
}

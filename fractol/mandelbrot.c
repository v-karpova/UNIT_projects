/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 20:31:31 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/03 20:31:33 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void	mandelbrot_thread(t_all *all)
{
	int			i;
	t_all		new_all[8];
	pthread_t	thread[8];

	i = -1;
	while (++i < 8)
	{
		ft_memcpy((void *)&new_all[i], (void *)all, sizeof(t_all));
		new_all[i].x = (WIN_X / 8) * i;
		new_all[i].x_max = (WIN_X / 8) * (i + 1);
	}
	i = -1;
	while (++i < 8)
		pthread_create(&thread[i], NULL, mandelbrot, &new_all[i]);
	i = -1;
	while (++i < 8)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}


void	*mandelbrot(void *v)
{
	t_all		*all;
	int			n;
	double		tmp_x;

	all = (t_all *)v;
	tmp_x = X;
	while (Y++ < IMG_H)
	{
		CI = 1.5 * (Y - IMG_H / 2) / (0.5 * ZOOM * IMG_H) + MV_Y;
		X = tmp_x;
		while (X++ < all->x_max)
		{
			CR = 1.5 * (X - IMG_W / 2) / (0.5 * ZOOM * IMG_W) + MV_X;
			ZI = CI;
			ZR = CR;
			n = -1;
			while (++n < MAX_ITER)
			{
				ZR2 = ZR * ZR;
				ZI2 = ZI * ZI;
				if (ZR2 + ZI2 > 4)
					break;
				ZI = 2 * ZR * ZI + CI;
				ZR = ZR2 - ZI2 + CR;
				if (n == MAX_ITER)
					pixel_put_img(all, X, Y, 0);
				else
					pixel_put_img(all, X, Y, COLOR * n);
			}
		}
	}
	return (all);
}

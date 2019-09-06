// /* ************************************************************************** */
// /*                                                                          */
// /*                                                        :::      ::::::::   */
// /*   stereo.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/07/25 16:29:32 by vkarpova          #+#    #+#             */
// /*   Updated: 2019/07/25 16:29:33 by vkarpova         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "rt.h"


// void			pixel_put_img_2(t_all *all, int x, int y, int color)
// {
// 	if (x < WIN_X && y < WIN_Y)
// 	{
// 		color = mlx_get_color_value(all->mlx_ptr, color);
// 		ft_memcpy(all->img_2 + 4 * WIN_X * y + x * 4, &color, sizeof(int));
// 	}
// 	all->img_2 =
// 	mlx_get_data_addr(all->img_ptr_2, &all->bpp, &all->size_line, &all->endian);
// }

void	stereo_init(t_all *all)
{
	all->cam_2 = plus(all->cam, init_vector(2, 0, 0, 0));
	all->opp = all->bpp / 8;
	all->img_ptr_2 = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	all->img_2 =
	mlx_get_data_addr(all->img_ptr_2, &all->bpp, &all->size_line, &all->endian);
}

void	stereoscopy(t_all *all)
{
	stereo_init(all);

	all->cam = init_vector(-0.5, 5, -50, 0);
	threads1(all);
	blue_stereo(all);

	all->cam = init_vector(0.5, 5, -50, 0);
	threads1(all);
	red_stereo(all);


	mlx_put_image_to_window(MLX_PTR, WIN_PTR, all->img_ptr_2, 0, 0);
}

void		blue_stereo(t_all *all)
{
	int	x;
	int	y;
	int	pos;

	pos = 0;
	x = -1;
	while (++x <= WIN_X)
	{
		y = - 1;
		while (++y <= WIN_Y)
		{
			pos = (x * all->opp) + (y * all->size_line);
			all->img_2[pos] += all->img[pos];
			all->img_2[pos + 1] += all->img[pos + 1];
			// pixel_put_img_2(all, x, - y, all->color);
		}
	}
}

void		red_stereo(t_all *all)
{
	int	x;
	int	y;
	int	pos;

	pos = 0;
	x = -1;
	while (++x <= WIN_X)
	{
		y = - 1;
		while (++y <= WIN_Y)
		{
			pos = (x * all->opp) + (y * all->size_line);
			all->img_2[pos + 2] += all->img[pos + 2];
			// pixel_put_img_2(all, x, - y, all->color);
		}
	}
}


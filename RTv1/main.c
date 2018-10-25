/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:09:30 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/17 15:09:31 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	usage(int o)
{
	o = 0;
	ft_putendl("usage: ");
}

void	set_img(t_all *all)
{
	all->cam.x = 0;
	all->cam.y = 0;
	all->cam.z = 0;

	all->d = 1;

	all->size_line = WIN_X;
	all->bpp = 32;
	all->endian = 0;
	// all->color = 0xF66E3FF;
	all->zoom = 0.5;
	all->img =
	mlx_get_data_addr(IMG_PTR, &all->bpp, &all->size_line, &all->endian);
}

void	do_it(t_all *all)
{
	sphere(all);
}

void	pixel_put_img(t_all *all, int x, int y, int color)
{
	if (x < WIN_X && y < WIN_Y)
	{
		color = mlx_get_color_value(all->mlx_ptr, color);
		ft_memcpy(all->img + 4 * WIN_X * y + x * 4, &all->sphere.color, sizeof(int));
	}
	all->img =
	mlx_get_data_addr(all->img_ptr, &all->bpp, &all->size_line, &all->endian);
}

void	go(t_all *all)
{
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "RTv1 vkarpova");
	IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);

	set_img(all);
	do_it(all);

	// mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	mlx_hook(WIN_PTR, 2, 5, event, all);
	// mlx_hook(WIN_PTR, 4, 1L << 2, mouse_press, all);
	// mlx_hook(WIN_PTR, 5, 1L << 3, mouse_release, all);
	// mlx_hook(WIN_PTR, 6, 1L << 13, mouse_move, all);
	// mlx_hook(WIN_PTR, 17, 1L << 17, x_close, all);
	mlx_loop(MLX_PTR);
}

int		main(int argc, char **argv)
{
	t_all		*all;
	// t_mouse		*m;
	t_vector	*vector;
	t_sphere	*sphere;
	int			o;

	o = 1;
	all = (t_all *)malloc(sizeof(t_all));
	// m = (t_mouse *)malloc(sizeof(t_mouse));
	vector = (t_vector *)malloc(sizeof(t_vector));
	sphere = (t_sphere *)malloc(sizeof(t_sphere));

	if (argc == 2)
		go(all);
	else
		usage(o);
	return (0);
}

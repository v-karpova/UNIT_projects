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

void	set_light(t_all *all)
{
	all->light.pos.x = 10;
	all->light.pos.y = 10;
	all->light.pos.z = -50;
	all->light.type = 1;
	all->light.intense = 0.6;

}

void	set_cone(t_all *all)
{
	all->cone.c.x = 0;
	all->cone.c.y = 0;
	all->cone.c.z = 3;

	all->cone.v.x = 1;
	all->cone.v.y = 0;
	all->cone.v.z = 0;

	all->cone.a = 0.2;

	all->cone.color = 0xFFF0000;
	all->cone.reflect = 0.3;
}

void	set_sphere(t_all *all)
{
	all->sphere.c.x = 0;
	all->sphere.c.y = 0;
	all->sphere.c.z = 5;
	all->sphere.r = 1;
	all->sphere.color = 0xFFF0000;
	all->sphere.reflect = 0.3;
}

void	set_cylinder(t_all *all)
{
	all->cylinder.c.x = 0;
	all->cylinder.c.y = 0;
	all->cylinder.c.z = 5;

	all->cylinder.v.x = 1;
	all->cylinder.v.y = 0;
	all->cylinder.v.z = 0;

	all->cylinder.r = 1;
	all->cylinder.color = 0xFFF0000;
	all->cylinder.reflect = 0.3;
}

void	set_plane(t_all *all)
{
	all->plane.color = 0xFFF0000;
	all->plane.reflect = 0.3;

	all->plane.c.x = 1;
	all->plane.c.y = 1;
	all->plane.c.z = 2;

	all->plane.v.x = 1;
	all->plane.v.y = 0;
	all->plane.v.z = 0;
}

void	set_img(t_all *all)
{
	all->cam.x = 0;
	all->cam.y = 0;
	all->cam.z = 0;

	set_light(all);
	set_sphere(all);
	set_cone(all);
	set_plane(all);
	set_cylinder(all);

	all->d = 1;

	all->size_line = WIN_X;
	all->bpp = 32;
	all->endian = 0;
	all->color = 0xFFF0000;
	all->zoom = 0.1;
	all->img =
	mlx_get_data_addr(IMG_PTR, &all->bpp, &all->size_line, &all->endian);
}

void	do_it(t_all *all)
{
	// sphere(all);
	// cone(all);
	plane(all);
	// cylinder(all);
}

void	pixel_put_img(t_all *all, int x, int y, int color)
{
	if (x < WIN_X && y < WIN_Y)
	{
		color = mlx_get_color_value(all->mlx_ptr, color);
		ft_memcpy(all->img + 4 * WIN_X * y + x * 4, &color, sizeof(int));
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

	mlx_hook(WIN_PTR, 2, 5, event, all);
	// mlx_hook(WIN_PTR, 4, 1L << 2, mouse_press, all);
	// mlx_hook(WIN_PTR, 5, 1L << 3, mouse_release, all);
	// mlx_hook(WIN_PTR, 6, 1L << 13, mouse_move, all);
	mlx_hook(WIN_PTR, 17, 1L << 17, x_close, all);
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

	if (argc == 1)
		go(all);
	else if (argc == 2)
		open_file(argv, all);
	else
		usage(o);
	return (0);
}

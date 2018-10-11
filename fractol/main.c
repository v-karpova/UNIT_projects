/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:58:47 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/01 17:59:14 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_img(t_all *all, int n)
{
 	all->x = -1;
	all->y = -1;
	all->mouse_x = -0.7;
	all->mouse_y = 0.27015;
	// all->jr = -0.7;
	// all->ji = 0.27015;
	all->iter = 1000;
	all->fract = n;
	all->size_line = WIN_X;
	all->bpp = 32;
	all->endian = 0;
	all->color = 0xFFFFFFF;
	all->move_x = 0;
	all->move_y = 0;
	all->change_x = 0;
	all->change_y = 0;
	all->zoom = 1;
	all->img =
	mlx_get_data_addr(all->img_ptr, &all->bpp, &all->size_line, &all->endian);
}

void	go(t_all *all, int n)
{
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "FRACTOL vkarpova");
	IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);

	set_img(all, n);
	all->img = 
	mlx_get_data_addr(IMG_PTR, &all->bpp, &all->size_line, &all->endian);
	now_do(all, n);
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	mlx_hook(WIN_PTR, 2, 5, event, all);
	mlx_hook(WIN_PTR, 4, 1L << 2, mouse_press, all);
	mlx_hook(WIN_PTR, 5, 1L << 3, mouse_release, all);
	mlx_hook(WIN_PTR, 6, 1L << 13, mouse_move, all);
	mlx_hook(WIN_PTR, 17, 1L << 17, x_close, all);
	mlx_loop(MLX_PTR);
}

int		name_check(char **argv)
{
	if (ft_strcmp(argv[1], "J") == 0)
		return (2);
	else if (ft_strcmp(argv[1], "M") == 0)
		return (1);
	else if (ft_strcmp(argv[1], "F") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "R") == 0)
		return (4);
	else if (ft_strcmp(argv[1], "H") == 0)
		return (5);
	else if (ft_strcmp(argv[1], "T") == 0)
		return (6);
	else if (ft_strcmp(argv[1], "MB") == 0)
		return (7);
	else if (ft_strcmp(argv[1], "S") == 0)
		return (8);
	return (0);
}

void	usage()
{
	ft_putendl("usage: ./fractol [choose fractol]");
	ft_putendl("1) M for Mandelbrot");
	ft_putendl("2) J for Julia");
	ft_putendl("3) F for Forever");
	ft_putendl("4) R for Rabbit");
	ft_putendl("5) H for Heart");
	ft_putendl("6) T for Tricorn");
	ft_putendl("7) MB for Mandelbar");
	ft_putendl("8) S for Snowflake");
}

int		main(int argc, char **argv)
{
	t_all		*all;
	t_mouse		*m;
	int			fd;

	all = (t_all *)malloc(sizeof(t_all));
	m = (t_mouse *)malloc(sizeof(t_mouse));
	if (argc == 2 && (name_check(argv)) >= 1)
		go(all, (name_check(argv)));
	else
		usage();
	return (0);
}

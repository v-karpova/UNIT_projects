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

void	now_do(t_all *all, int n)
{
	if (n == 1)
		mandelbrot(all);
	else if (n == 2)
		julia(all);
	else if (n == 3)
	 	THIRD(all);


	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
}

void	go(t_all *all, int n)
{
	MLX_PTR = mlx_init();
	WIN_PTR = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "FRACTOL vkarpova");
	IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	all->img = 
	mlx_get_data_addr(all->img_ptr, &all->bpp, &all->size_line, &all->endian);

	now_do(all, n);

	all->img = 
		mlx_get_data_addr(all->img_ptr, &all->bpp, &all->size_line, &all->endian);

	mlx_hook(WIN_PTR, 2, 5, event, all);
	mlx_hook(WIN_PTR, 4, 1L << 2, mouse_press, all);
	mlx_hook(WIN_PTR, 5, 1L << 3, mouse_release, all);
	mlx_hook(WIN_PTR, 6, 1L << 13, mouse_move, all);
	mlx_hook(WIN_PTR, 17, 1L << 17, x_close, all);

	mlx_loop(MLX_PTR);
}

int		name_check(char **argv)
{
	if (ft_strcmp(argv[1], "Julia") == 0)
		return (2);
	else if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(argv[1], "THIRD") == 0)
		return (3);
	return (0);
}

void	set_img(t_all *all)
{
	all->size_line = WIN_X;
	all->bpp = 32;
	all->endian = 0;
	all->movex = 0;
	all->movey = 0;
	all->colour = 265;
	all->zoom = 1;
	all->img =
	mlx_get_data_addr(all->img_ptr, &all->bpp, &all->size_line, &all->endian);
}

int		main(int argc, char **argv)
{	
	t_all	*all;
	int		fd;

	all = (t_all *)malloc(sizeof(t_all));
	if (argc == 2 && (name_check(argv)) >= 1)
	{
		set_img(all);
		go(all, (name_check(argv)));
	}
	else
		ft_putendl("usage: ./fractol [fractol]\n->Mandelbrot\n->Julia\n->THIRD");
	return (0);
}

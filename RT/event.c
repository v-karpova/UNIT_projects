/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:21:15 by vkarpova          #+#    #+#             */
/*   Updated: 2019/04/23 18:21:16 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// void	threads1(t_all *all)
// {
// 	int			i;
// 	t_all		new_all[8];
// 	pthread_t	thread[8];

// 	i = -1;
// 	while (++i < 8)
// 	{
// 		ft_memcpy((void *)&new_all[i], (void *)all, sizeof(t_all));
// 		new_all[i].x = (WIN_X / 8) * i;
// 		new_all[i].x_max = (WIN_X / 8) * (i + 1);
// 	}
// 	i = -1;
// 	while (++i < 8)
// 		pthread_create(&thread[i], NULL, threads2, &new_all[i]);
// 	i = -1;
// 	while (++i < 8)
// 		pthread_join(thread[i], NULL);
// 	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
// }

// void	*threads2(void *v)
// {
// 	t_all		*all;
// 	double		tmp_x;

// 	all = (t_all *)v;
// 	do_it(all);
// 	return (all);
// }


int			event(int key, t_all *all)
{
	mlx_clear_window(MLX_PTR, WIN_PTR);

	if (key == 53)
	{
		// mlx_clear_window(MLX_PTR, WIN_PTR);
		free(all);
		// system("leaks a.out");
		exit(0);
	}
	
	else if (key == 123)
	{
		all->cam.x -= 1; 
	}
	else if (key == 124)
	{
		all->cam.x += 1; 
	}
	else if (key == 125)
	{
		all->cam.y -= 1; 
	}
	else if (key == 126)
	{
		all->cam.y -= 1; 
	}
	else if (key == 2)
	{
		all->cam.z -= 2; 
	}
	else if (key == 1)
	{
		all->cam.z += 2; 
	}

	else if (key == 49)
	{
		((t_light *)(all->light->content))->pos.x += 2; 
	}

	do_it(all);
	// threads1(all);
	return (0);
}


int		mouse_press(int button, int x, int y, t_all *all)
{
	if (button == 2)
		event(9, all);
	else if (button == 4)
		event(1, all);
	else if (button == 5)
		event(2, all);
	else if (button == 1)
		all->mouse.press = 1;
	x = y;
	return (0);
}

int		mouse_release(int button, int x, int y, t_all *all)
{
	if (button == 1)
		all->mouse.press = 0;
	x = y;
	return (0);
}

int		mouse_move(int x, int y, t_all *all)
{
	if (all->mouse.press == 1)
		all->mouse.press = 2;
	else if (all->mouse.press == 2)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		// rotat_x(all, (double)(all->mouse.x - x) / 200);
		// rotat_y(all, (double)(all->mouse.y - y) / 200);

		all->rot.x = (all->mouse.x - x) / 20;
		all->rot.y = (all->mouse.y - y) / 20;
		do_it(all);
	}
	all->mouse.x = x;
	all->mouse.y = y;
	return (0);
}


// void	rotat_x(t_all *all, double angle)
// {
// 	double	y;

// 	y = all->rot.y;
// 	all->rot.y = y * cos(angle) + all->rot.z * sin(angle);
// 	all->rot.z = -y * sin(angle) + all->rot.z * cos(angle);
// }

// void	rotat_y(t_all *all, double angle)
// {
// 	double	x;

// 	x = all->rot.x;
// 	all->rot.x = x * cos(angle) + all->rot.z * sin(angle);
// 	all->rot.z = -x * sin(angle) + all->rot.z * cos(angle);
// }

// void	rotat_z(t_all *all, double angle)
// {
// 	double	x;


// 	x = all->rot.x;
// 	all->rot.x = x * cos(angle) + all->rot.y * sin(angle);
// 	all->rot.y = -x * sin(angle) + all->rot.y * cos(angle);
// }

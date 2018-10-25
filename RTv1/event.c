/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:37:17 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/22 13:37:18 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int			event(int key, t_all *all)
{
	// mlx_destroy_image(MLX_PTR, IMG_PTR);
	// IMG_PTR = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	if (key == 53)
	{
		mlx_clear_window(MLX_PTR, WIN_PTR);
		free(all);
		exit(0);
	}
	return (0);
}

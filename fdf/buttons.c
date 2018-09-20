/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:46:46 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/19 18:47:03 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		event(int key, t_all *all)
{
		if (key == 53)         // ECS
	    {
		    free(all);
		    exit(0);
    	}
		else if (key == 12)         // Q zoom--
	    {
			mlx_clear_window(MLX_PTR, WIN_PTR);
		    zoom(all, -1);
			draw(all);
    	}
		else if (key == 14)         // E zoom++
	    {
			mlx_clear_window(MLX_PTR, WIN_PTR);
		    zoom(all, 1);
			draw(all);
    	}
		
        return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:23:31 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/18 15:23:34 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include "fdf.h"

// int mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );


t_all   draw(t_all all)
{
    all.mlx_ptr = mlx_init();
    all.win_ptr = mlx_new_window(all.mlx_ptr, 2000, 1000, "FDF is love");

 
    mlx_pixel_put(all.mlx_ptr, all.win_ptr, 250, 250, 0x00FF0000);
    return (all);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 20:21:09 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/19 20:21:11 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	center(t_all *all)
{

	all->center[0] = all->matrix[MAX_Y / 2][MAX_X / 2].x;
	all->center[1] = all->matrix[MAX_Y / 2][MAX_X / 2].y;
	all->center[2] = all->matrix[MAX_Y / 2][MAX_X / 2].z;

    // mlx_pixel_put(MLX_PTR, WIN_PTR, all->center[0], all->center[1], 0x00FF0000);   
    // printf("center %f,%f,%f \n", all->center[0], all->center[1], all->center[2]);
}

t_matrix    *save_coords(char *line, int line_nb, t_all *all)
{
    t_matrix    *coords;
    char        **split;
    int         i;

    split = ft_strsplit(line, ' ');
    i = 0;
    coords = (t_matrix *)malloc(sizeof(t_matrix) * all->map_x);
    while (split[i] != '\0')
    {
        coords[i].x = i;
        coords[i].y = line_nb;
        coords[i].z = atoi(split[i]);
        // printf("(%d,%d,%d) ", coords[i].x, coords[i].y, coords[i].z);
        i++;
    }
    // printf("\n");
    return (coords);
}


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

#include "fdf.h"

void    print(t_matrix **matrix, int max_x, int max_y)
{
    int     line;
    int     pos;

    line = 0;
    while (line < max_y)
    {
        pos = 0;
        while (pos < max_x)
        {
            printf("(%d,%d,%d) ", matrix[line][pos].x, matrix[line][pos].y,matrix[line][pos].z);
            pos++;
        }
        printf("\n");
        line++;
    }
}

// void    draw(t_all *all)
// {
//     int     line;
//     int     pos;
  
//     make_line(all, &all->matrix[0][10], &all->matrix[10][10]);
//     // line = 0;
//     // while (line < MAX_Y)
//     // {
//     //     pos = 0;
//     //     while (pos < MAX_X - 1)
//     //     {
//     //         make_line(all, &all->matrix[line][pos], &all->matrix[line][pos + 1]);
//     //         pos++;
//     //     }
//     //     line++;
//     // }
// }


void   go(t_all *all)
{

    all->mlx_ptr = mlx_init();
printf("------------------\n");
    all->win_ptr = mlx_new_window(all->mlx_ptr, WIN_X, WIN_Y, "FDF vkarpova");

    // draw(all);

    mlx_hook(WIN_PTR, 2, 5, event, all);

    mlx_loop(all->mlx_ptr);

}

void	make_line(t_all *all, t_matrix *c1, t_matrix *c2)
{
	int		xy[2];

	xy[0] = c1->x;
	xy[1] = c1->x;
	if (abs(c2->y - c1->y) > abs(c2->x - c1->x))
		while (c1->y > c2->y ? xy[1] >= c2->y : xy[1] <= c2->y)
		{
			xy[0] = ((xy[1] - c1->y) / (c1->y - c2->y) * (c1->x - c2->x) + c1->x);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], 0x00FFFFFF);
			c2->y > c1->y ? xy[1]++ : xy[1]--;
		}
	else
		while (c1->x > c2->x ? xy[0] >= c2->x : xy[0] <= c2->x)
		{
			xy[1] = ((xy[0] - c1->x) / (c1->x - c2->x) * (c1->y - c2->y) + c1->y);
			mlx_pixel_put(MLX_PTR, WIN_PTR, xy[0], xy[1], 0x00FFFFFF);
			c2->x > c1->x ? xy[0]++ : xy[0]--;
		}
}

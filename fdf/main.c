/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:48:40 by vkarpova          #+#    #+#             */
/*   Updated: 2018/08/17 16:32:36 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/*clear && gcc ./libft-*.c main.c read_map.c get_next_line.c draw.c -lmlx -framework OpenGL -framework AppKit */

int     deal_key(int key, void *param)
{
    ft_putstr("->the button was pressed\n");
    return (0);
}

void    error_msg(int code)
{
    if (code == 1)
        ft_putstr("usage: ./fdf your_map\n");
    else if (code == 2)
        ft_putstr("invalid map, try add another one\n");    
}

int main(int argc, char **argv)
{
    t_all   all;

    if (argc == 2)
    {
//  ??      all = malloc(sizeof(t_all));
        all = read_file(argv, all);
        if (all.map_x == -1)
       {
          error_msg(2);
          return (0);
        }

        all = draw(all);

// printf("-------OK--------\n");

    // mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x00FFFFFF);
    // mlx_string_put(mlx_ptr, win_ptr, 10,10, 0x00FFFFFF, "MAP: 42\n");
    // mlx_string_put(mlx_ptr, win_ptr, 10,30, 0x00FFFFFF, "--------\n");
    // mlx_string_put(mlx_ptr, win_ptr, 10,50, 0x00FFFFFF, "CONTROL:\n");
    // mlx_string_put(mlx_ptr, win_ptr, 10,70, 0x00FFFFFF, "left   <\n");
    // mlx_string_put(mlx_ptr, win_ptr, 10,90, 0x00FFFFFF, "right  >\n");

    // mlx_key_hook(win_ptr, deal_key, (void *)0);
 
    

// int mlx_clear_window ( void *mlx_ptr, void *win_ptr );
// int mlx_destroy_window ( void *mlx_ptr, void *win_ptr );
        mlx_loop(all.mlx_ptr);
    }
    else 
        error_msg(1);
    return(0);
}

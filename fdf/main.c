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

#include "./libft/libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include "fdf.h"

/*  gcc ./libft-*.c main.c get_next_line.c -lmlx -framework OpenGL -framework AppKit */

int     deal_key(int key, void *param)
{
    ft_putstr("->the button was pressed\n");
    return (0);
}

void    error_msg(int code)
{
    if (code == 1)
        ft_putstr("wrong number of arguments, add one map, please\n");
    else if (code == 2)
        ft_putstr("wrong map, try add another one\n");
}

int main(int argc, char **argv)
{
    int ret;

    if (argc != 2)
        error_msg(1);
//    else if ((ret = get_next_line(fd, &line)) == -1)
//       error_msg(2);

	read_file(argv);


/*    void *mlx_ptr;
    void *win_ptr;
    int close_win;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FDF is love");
    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0x00FFFFFF);
    mlx_key_hook(win_ptr, deal_key, (void *)0);
    mlx_loop(mlx_ptr);
*/

   // if PRESS ESC (53 button) -> mlx_destroy_window(mlx_ptr, win_ptr);
  
    return(0);
}

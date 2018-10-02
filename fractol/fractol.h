/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:34:28 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/01 17:34:31 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define WIN_X 2550
# define WIN_Y 1300
# define MLX_PTR all->mlx_ptr
# define WIN_PTR all->win_ptr
# define MIN_R -2.0
# define MAX_R 1.0
# define MIN_I -1.2
# define MAX_I MIN_I + (MAX_R - MIN_R) * IMAGE_H / IMAGE_W
# define IMAGE_H 500 // ???
# define IMAGE_W 500 // ???
# define R_FACTOR (MAX_R - MIN_R) / (IMAGE_W - 1)
# define I_FACTOR (MAX_I - MIN_I) / (IMAGE_H - 1)
# define CR_J -0.7
# define CI_J 0.27015
# define MAX_ITER 30

# define CR all->c_r
# define CI all->c_i
# define ZR all->Z_r
# define ZI all->Z_i
# define ZR2 all->Z_r2
# define ZI2 all->Z_i2
# define INSIDE all->isInside

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "math.h"
# include "mlx.h"
# include "libft/libft.h"

typedef struct	s_mouse
{
	char		press;
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_all
{
	t_mouse		mouse;
	void		*mlx_ptr;
	void		*win_ptr;
	double		c_r;
	double		c_i;
	double		Z_r;
	double		Z_i;
	double		Z_r2;
	double		Z_i2;
	int			isInside;

}				t_all;

void	go(t_all *all, int n);
int		main(int argc, char **argv);
int		event(int key, t_all *all);
int		mouse_press(int button, int x, int y, t_all *all);
int		mouse_release(int button, int x, int y, t_all *all);
int		mouse_move(int x, int y, t_all *all);
int		x_close(t_all *all);
int		name_check(char **argv);
void	mandelbrot(t_all *all);
void	julia(t_all *all);



#endif

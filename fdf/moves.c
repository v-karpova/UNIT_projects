/* ************************************************************************** */
/*		                                                                         */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:42:48 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/20 16:43:01 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_all *all, int where)
{
	int		line;
	int		pos;
		
	line = 0;
	while (line < MAX_Y)
	{
		pos = 0;
		while (pos < MAX_X)
		{
			if (where == 1)				//right
				all->matrix[line][pos].x += 10;
			else if (where == -1)		//left
				all->matrix[line][pos].x -= 10;
			else if (where == 2)		 //up
				all->matrix[line][pos].y -= 10;
			else if (where == -2)		//down
				all->matrix[line][pos].y += 10;
			pos++;
		}
		line++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:03:40 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/26 16:03:42 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		rgb_to_int(t_vector C)
{
	int		rgb;

	rgb = C.x;
	rgb = (rgb << 8) + C.y;
	rgb = (rgb << 8) + C.z;

	return (rgb);
}

t_vector	int_to_rgb(int rgb)
{
	t_vector	C;

	C.x = (rgb >> 16) & 0xFF;
	C.y = (rgb >> 8) & 0xFF;
	C.z = rgb & 0xFF;

	return (C);
}
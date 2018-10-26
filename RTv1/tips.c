/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tips.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:53:42 by vkarpova          #+#    #+#             */
/*   Updated: 2018/10/23 14:53:59 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RTv1.h"


// Vector == ray
// p = S + t * D
// p - определенная точка на векторе
// S - source(start) of the ray
// t - time or distance
// D - direction

// X = Xs + t * Xd;
// Y = Ys + t * Yd;
// Z = Zs + t * Zd;

// 			SPHERE equation
// (X - Xc)^2 + (Y - Yc)^2 + (Z - Zd)^2  = r^2
//			трансформируется в 
// (Xs + t * Xd - Xc) * (Xs + t * Xd - Xc) +
// + (Ys + t * Yd - Yc) * (Ys + t * Yd - Yc) +
// + (Zs + t * Zd - Zc) * (Zs + t * Zd - Zc) = r * r;
//			трансформируется в 
// (Xd^2*t^2 + 2 * (Xd*(Xs-Xc)*t) + (Xs - Xc)^2 ) +
// (Yd^2*t^2 + 2 * (Yd*(Ys-Yc)*t) + (Ys - Yc)^2 ) +
// (Zd^2*t^2 + 2 * (Zd*(Zs-Zc)*t) + (Zs - Zc)^2 ) - r^2;

// 			то есть это 
// ax^2 + bx + c = 0
// a = Xd^2 + Yd^2 + Zd^2
// 		if d normalized, then 
// a = 1
// b = 2*(Xd*(Xs-Xc) + (Yd*(Ys-Yc) + (Zd*(Zs-Zc)
// c = (Xs - Xc)^2 + (Ys - Yc)^2 + (Zs - Zc)^2

// t1 = (-b + sqrt(b*b - 4*c)) / 2
// t2 = (-b - sqrt(b*b - 4*c)) / 2

// CHECK INTERSECTION
// b = 2*(Xd*(Xs-Xc) + (Yd*(Ys-Yc) + (Zd*(Zs-Zc)
// c = (Xs - Xc)^2 + (Ys - Yc)^2 + (Zs - Zc)^2
// >>>>>>>>>>>
// if (b*b - 4c) < 0  >> No intesection
// 				 <=0 >> 1 point
//				 > 0   >> 2 point, so the raygo through  
// ограничение на t !!!!!!!!! каким-то большим числом
// < 0 	-> за камерой
// 0-1 	-> между камерой и плоскостью проекции
// > 1 	-> сцена

// Vector x= a; y =b; z = c;
//  Ray -> (t_vector *one, t_vector *two)
//  Sphere -> 






// t_vector	*CanvasToViewport(double x, double y)
// {
// 	t_vector	*new;
// 	// double		d;
// 	// double		Vw;
// 	// double		Vh;

// 	// printf("CanvasToViewport\n");
// 	// d = 1;
// 	// Vw = 1;
// 	// Vh = 1;
// 	new->x = x / WIN_X;
// 	new->y = y / WIN_Y;
// 	new->z = 1;
// 	// printf("new(%f,%f,%f)\n", new->x, new->y, new->z);
// 	// printf("CanvasToViewport1\n");
// 	return (new);
// }








// t_vector	*send_ray(int x, int y)
// {
// 	t_vector	*a;
// 	t_vector	*b;
// 	t_vector	*new;

// 	a->x = x;
// 	a->y = y;
// 	a->z = 0;

// 	b->x = 0;
// 	b->y = 0;
// 	b->z = 1;
// 	new = do_vector(a, b);
// 	return (new);
// }





// int		is_in_sphere(t_vector *vector)
// {
// 	double	b;
// 	double	c;
// 	double	disc;
// 	// double	t0;
// 	// double	t1;
// 	// double	t;

// 	b = 2*(XD*(XS-XC)) + (YD*(YS-YC)) + (ZD*(ZS-ZC));
// 	c = (XS - XC) * (XS - XC) + (YS - YC) * (YS - YC) + (ZS - ZC) * (ZS - ZC) - R * R;
// 	disc = b * b - 4 * c;

// 	// disc = sqrt(b * b - 4 * c);
// 	// t0 = -b - disc;
// 	// t1 = -b + disc;
// 	// t = (t0 < t1) ? t0 : t1; // -ближайшая к камере точка  

// 	if (disc < 0)
// 		return (0);
// 	else
// 		return (1);
// }


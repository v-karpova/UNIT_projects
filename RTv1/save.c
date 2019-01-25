/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:45:11 by vkarpova          #+#    #+#             */
/*   Updated: 2018/11/02 18:45:15 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		save_reflect(t_all *all, double *reflect)
{
	char		*line;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " specular:", 10) == 0))
	{
		*reflect = (double)ft_atoi(&line[10]);
		if (*reflect >= 0 && *reflect <= 1000)
			return (1);
		else
			*reflect = 1000;
		return (1);
	}
	return (0);
}

int		save_angle(t_all *all, double *angle)
{
	char		*line;
	double		tmp; 

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " angle:", 7) == 0))
	{
		tmp = (double)ft_atoi(&line[7]) / 2;
		*angle = tan(tmp);
		return (1);
	}
	return (0);
}

int		save_radius(t_all *all, double *radius)
{
	char		*line;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " radius:", 8) == 0))
	{
		*radius = (double)ft_atoi(&line[8]);
		return (1);
	}
	return (0);
}

int		save_pos(t_all *all, t_vector *pos)
{
	char		*line;
	char		**tmp;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " position:", 10) == 0))
	{
		tmp = ft_strsplit(&line[10], ',');
		pos->x = (double)ft_atoi(tmp[0]);
		pos->y = (double)ft_atoi(tmp[1]);
		pos->z = (double)ft_atoi(tmp[2]);
		free(tmp);
		return (1);
	}
	return (0);
}

int		save_intense(t_all *all, double *intense)
{
	char		*line;
	double		tmp;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " intense:", 9) == 0))
	{
		tmp = (double)ft_atoi(&line[9]);
		if (tmp >= 0 && tmp <= 10)
			*intense = tmp / 10;
		else
			*intense = 1;
		return (1);
	}
	return (0);
}

int		save_color(t_all *all, int *color)
{
	char		*line;
	t_vector	C;
	char		**tmp;
	
	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " color:", 7) == 0))
	{
		tmp = ft_strsplit(&line[7], ',');
		C.x = (double)ft_atoi(tmp[0]);
		C.y = (double)ft_atoi(tmp[1]);
		C.z = (double)ft_atoi(tmp[2]);
		*color = rgb_to_int(C);
		free(tmp);
		return (1);
	}
	return (0);
}

int		save_normal(t_all *all, t_vector *norm)
{
	char		**tmp;
	char		*line;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " normal:", 8) == 0))
	{
		tmp = ft_strsplit(&line[8], ',');
		norm->x = (double)ft_atoi(tmp[0]);
		norm->y = (double)ft_atoi(tmp[1]);
		norm->z = (double)ft_atoi(tmp[2]);
		free(tmp);
		return (1);
	}
	return (0);
}

int		save_center(t_all *all, t_vector *center)
{
	char		**tmp;
	char		*line;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, " center:", 8) == 0))
	{
		tmp = ft_strsplit(&line[8], ',');
		center->x = (double)ft_atoi(tmp[0]);
		center->y = (double)ft_atoi(tmp[1]);
		center->z = (double)ft_atoi(tmp[2]);
		free(tmp);
		return (1);
	}
	return (0);
}

t_vector	save_cam(char *line)
{
	t_vector	C;
	char		**tmp;

	tmp = ft_strsplit(&line[7], ',');
	C.x = (double)ft_atoi(tmp[0]);
	C.y = (double)ft_atoi(tmp[1]);
	C.z = (double)ft_atoi(tmp[2]);
	free(tmp);
	return (C);
}

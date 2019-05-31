/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:53:02 by vkarpova          #+#    #+#             */
/*   Updated: 2019/02/01 17:53:03 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		save_reflect(t_all *all, double *reflect)
{
	char		*line;
	double		tmp;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, "-specular:", 10) == 0))
	{
		if (num(ft_strchr(line, ':') + 1))
		{
			tmp = (double)ft_atoi(&line[10]);
			free(line);
			if (tmp >= 0 && tmp <= 1000)
				*reflect = tmp;
			else if (tmp < 0)
				return (0);
			else
				*reflect = 1000;
			return (1);
		}
	}
	return (0);
}

int		save_angle(t_all *all, double *angle)
{
	char		*line;
	double		tmp;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, "-angle:", 7) == 0))
	{
		if (num(ft_strchr(line, ':') + 1))
		{
			tmp = (double)ft_atoi(&line[7]);
			free(line);
			if (tmp <= 0 || tmp > 360)
				return (0);
			*angle = tan(tmp / 2);
			return (1);
		}
	}
	return (0);
}

int		save_radius(t_all *all, double *radius)
{
	char		*line;
	double		tmp;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, "-radius:", 8) == 0))
	{
		if (num(ft_strchr(line, ':') + 1))
		{
			tmp = (double)ft_atoi(&line[8]);
			free(line);
			if (tmp < 0)
				return (0);
			else
				*radius = tmp;
			return (1);
		}
	}
	return (0);
}

int		save_pos(t_all *all, t_vector *pos)
{
	char		*line;
	char		**tmp;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, "-position:", 10) == 0))
	{
		tmp = ft_strsplit(&line[10], ',');
		free(line);
		if (num(tmp[0]) && num(tmp[1]) && num(tmp[2]) && tmp[3] == NULL)
		{
			pos->x = (double)ft_atoi(tmp[0]);
			pos->y = (double)ft_atoi(tmp[1]);
			pos->z = (double)ft_atoi(tmp[2]);
			free(tmp[1]);
			free(tmp[2]);
			free(*tmp);
			free(tmp);
			return (1);
		}
	}
	return (0);
}

int		save_intense(t_all *all, double *intense)
{
	char		*line;
	double		tmp;

	if ((get_next_line(all->fd, &line) > 0) &&
		(ft_strncmp(line, "-intense:", 9) == 0))
	{
		if (num(ft_strchr(line, ':') + 1))
		{
			tmp = (double)ft_atoi(&line[9]);
			free(line);
			if (tmp >= 0 && tmp <= 10)
				*intense = tmp / 10;
			else if (tmp < 0)
				return (0);
			else
				*intense = 1;
			return (1);
		}
	}
	return (0);
}

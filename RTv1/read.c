/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 20:12:24 by vkarpova          #+#    #+#             */
/*   Updated: 2018/11/01 20:12:26 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"


//			МОЖЕТ ЧИТАТЬ ФАЙЛ

//			ЗАЧЕМ ДЕЛАТЬ СТРУКТУРУ obj, ЕСЛИ ЕСТЬ all ??
//			ДОБАВИТЬ ЛИСТЫ, ЧТОБ МОЖНО ЕЩЕ БЫЛО ДОБАВЛЯТЬ ПО НЕСКОЛЬКО СФЕР, НАПРИМЕР
//			ЧТО С НОРМАЛЬЮ? В КАКОЙ МОМЕНТ НОРМАЛИЗИРОВАТЬ V
//			ФОРМУЛА КОНУСА - ИСПРАВИТЬ, ЧТО ДЕЛАТЬ С УГЛОМ (РАДИАНЫ ??)




void	error(int n)
{
	if (n == 1)
		ft_putendl("can't open file, try another one");
}

void	open_file(char **argv, t_all *all)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error(1);
		return ;
	}
	read_file(all, fd);
}

void	read_file(t_all *all, int fd)
{
	char	*line;
	char	**tmp;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "camera:", 7) == 0)
			all->cam = save_cam(line, all);
		if (ft_strncmp(line, "#light", 6) == 0)
			while (get_next_line(fd, &line) > 0 && *line != '\0')
			{
				save_light(line, all);
				free(line);
			}
		if (ft_strncmp(line, "#plane", 6) == 0)
			while (get_next_line(fd, &line) > 0 && *line != '\0')
			{
				save_plane(line, all);
				free(line);
			}
		if (ft_strncmp(line, "#cylinder", 9) == 0)
			while (get_next_line(fd, &line) > 0 && *line != '\0')
			{
				save_cylinder(line, all);
				free(line);
			}
		if (ft_strncmp(line, "#cone", 5) == 0)
			while (get_next_line(fd, &line) > 0 && *line != '\0')
			{
				save_cone(line, all);
				free(line);
			}
		if (ft_strncmp(line, "#sphere", 7) == 0)
			while (get_next_line(fd, &line) > 0 && *line != '\0')
			{
				save_sphere(line, all);
				free(line);
			}
		free(line);
	}
	printf("\nOUT !\n");
	printf("cam(%f, %f, %f)\n", all->cam.x, all->cam.y, all->cam.z);
	printf("light intense = %f\n", all->light.intense);
	printf("light(%f, %f, %f)\n", all->light.pos.x, all->light.pos.y, all->light.pos.z);

	printf("\nplane color = %d\n", all->plane.color);
	printf("plane reflect = %f\n", all->plane.reflect);
	printf("plane norm(%f, %f, %f)\n", all->plane.v.x, all->plane.v.y, all->plane.v.z);
	printf("plane center(%f, %f, %f)\n", all->plane.c.x, all->plane.c.y, all->plane.c.z);

	printf("\ncylinder color = %d\n", all->cylinder.color);
	printf("cylinder r = %f\n", all->cylinder.r);
	printf("cylinder reflect = %f\n", all->cylinder.reflect);
	printf("cylinder norm(%f, %f, %f)\n", all->cylinder.v.x, all->cylinder.v.y, all->cylinder.v.z);
	printf("cylinder center(%f, %f, %f)\n", all->cylinder.c.x, all->cylinder.c.y, all->cylinder.c.z);

	printf("\ncone color = %d\n", all->cone.color);
	printf("cone angle = %f\n", all->cone.a);
	printf("cone reflect = %f\n", all->cone.reflect);
	printf("cone norm(%f, %f, %f)\n", all->cone.v.x, all->cone.v.y, all->cone.v.z);
	printf("cone center(%f, %f, %f)\n", all->cone.c.x, all->cone.c.y, all->cone.c.z);

	printf("\nsphere color = %d\n", all->sphere.color);
	printf("sphere r = %f\n", all->sphere.r);
	printf("sphere reflect = %f\n", all->sphere.reflect);
	printf("sphere center(%f, %f, %f)\n", all->sphere.c.x, all->sphere.c.y, all->sphere.c.z);
}

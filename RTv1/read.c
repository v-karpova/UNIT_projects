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

void	error(int n)
{
	if (n == 1)
		ft_putendl("can't open file, try another one");
}

void	open_file(char **argv, t_obj *obj, t_all *all)
{	
	all->fd = open(argv[1], O_RDONLY);
	if (all->fd == -1)
	{
		error(1);
		return ;
	}
	read_file(obj, all);
	print(obj, all);
}

void	read_file(t_obj *obj, t_all *all)
{
	char	*line;
	t_list	*tmp;

	while (get_next_line(all->fd, &line) > 0)
	{
		if (ft_strncmp(line, "camera:", 7) == 0)
			all->cam = save_cam(line);
		else if (ft_strncmp(line, "#light", 6) == 0)
			save_light(all);
		else if (ft_strncmp(line, "#plane", 6) == 0)
			save_plane(all);
		else if (ft_strncmp(line, "#cylinder", 9) == 0)
			save_cylinder(all);
		else if (ft_strncmp(line, "#cone", 5) == 0)
			save_cone(all);
		else if (ft_strncmp(line, "#sphere", 7) == 0)
			save_sphere(all);
		free(line);
	}
}

void	print(t_obj *obj, t_all *all)
{
	int		i;
	t_list	*list;

	list = all->obj;
	i = 1;
	// printf("\nFILE !\n");
	while (list != NULL)
	{
		printf("%d - ", i);
		if (list->content_size == CAM)
			printf("camera\n");
		else if (list->content_size == LIGHT)
			printf("light\n");
		else if (list->content_size == CONE)
			printf("cone\n");
		else if (list->content_size == CYL)
			printf("cylinder\n");
		else if (list->content_size == SPHERE)
			printf("sphere\n");
		else if (list->content_size == PLANE)
			printf("plane\n");
		else 
			printf("PROBLEM !\n");
		i++;
		list = list->next;
	}
	if (list == NULL)
			printf("NULL\n");
}

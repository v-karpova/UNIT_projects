/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <vkarpova@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:54:48 by vkarpova          #+#    #+#             */
/*   Updated: 2019/09/06 15:54:49 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

#  define FLAGS S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH


typedef struct			s_name
{
	char	type[2];
	int		reserved;
	int		file_size;
	int		offset;
}						t_name;

typedef struct			s_screenshot
{
	int		w;
	int		h;
	short	bpp;

	int		name_size;
	int		image_size;

	int		nb_color;
	int		important_color;
	int		compression;
	int		x;
	int		y;
	short	panes;
}						t_screenshot;


static char	*screenshot_name(t_all *all)
{
	time_t	time0;
	char	*del;
	char	*buf;
	char	*f_name;

	time(&time0);
	buf = ft_strdup(all->scene_name);
	del = buf;
	buf = ft_strrchr(buf, '/');
	buf[ft_strrchr(buf, '.') - buf] = '\0';
	buf = ft_strjoin(buf, "_%d_%m_%Y_%H-%M-%S");
	ft_strdel(&del);
	f_name = ft_strnew(128);
	strftime(f_name, 128, buf, localtime(&time0));
	ft_strdel(&buf);
	del = f_name;
	f_name = ft_strjoin("./screenshots", f_name);		// сделать папку screenshots
	ft_strdel(&del);
	del = f_name;
	f_name = ft_strjoin(f_name, ".bmp");
	ft_strdel(&del);
	return (f_name);
}

static void	make_screenshot_name(t_name *name, t_screenshot *screen, t_all *all)
{
	name->type[0] = 0x42;
	name->type[1] = 0x4D;
	name->file_size = 54 + (all->size_line * WIN_Y);
	name->reserved = 0x00000000;
	name->offset = 54;
	screen->name_size = 40;
	screen->h = WIN_X;
	screen->w = WIN_Y;
	screen->panes = 1;
	screen->bpp = 24;
	screen->compression = 0;
	screen->image_size = all->size_line * WIN_X;
	screen->x = 2835;
	screen->y = 2835;
	screen->nb_color = 0;
	screen->important_color = 0;
}

static void	make_screenshot_name_2(const int fd, t_name name, t_screenshot screen)
{
	write(fd, &name.type, 2);
	write(fd, &name.file_size, 4);
	write(fd, &name.reserved, 4);
	write(fd, &name.offset, 4);
	write(fd, &screen.name_size, 4);
	write(fd, &screen.w, 4);
	write(fd, &screen.h, 4);
	write(fd, &screen.panes, 2);
	write(fd, &screen.bpp, 2);
	write(fd, &screen.compression, 4);
	write(fd, &screen.image_size, 4);
	write(fd, &screen.x, 4);
	write(fd, &screen.y, 4);
	write(fd, &screen.nb_color, 4);
	write(fd, &screen.important_color, 4);
}

static char	*copy_img(t_all *all, t_screenshot *screen)
{
	int		i;
	int		j;
	int		k;
	char	*copy;

	i = screen->image_size - 1;
	j = 0;
	copy = (char*)malloc(sizeof(char) * screen->image_size);
	while (i >= 0)
	{
		i -= all->size_line;
		k = 0;
		while (k < all->size_line)
		{
			copy[j] = all->img[i + k + 1];
			copy[j + 1] = all->img[i + k + 2];
			copy[j + 2] = all->img[i + k + 3];
			j += 3;
			k += 4;
		}
	}
	return (copy);
}

void		screenshot(t_all *all)
{
	int				fd;
	char			*img;
	t_name			name;
	t_screenshot	screen;

	all->scene_name = screenshot_name(all);
	fd = open(all->scene_name, O_WRONLY | O_CREAT, FLAGS);
	ft_strdel(&all->scene_name);
	make_screenshot_name(&name, &screen, all);
	make_screenshot_name_2(fd, name, screen);
	img = copy_img(all, &screen);
	write(fd, img, screen.image_size);
	ft_strdel(&img);
	close(fd);
}

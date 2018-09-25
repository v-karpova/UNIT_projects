/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:12:12 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/25 19:12:15 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*clear && gcc ./libft-*.c main.c moves.c work.c get_next_line.c draw.c buttons.c -lmlx -framework OpenGL -framework AppKit */

void	error_msg(int code)
{
	if (code == 1)
		ft_putstr("usage: ./fdf your_map\n");
	else if (code == 2)
		ft_putstr("invalid map, try add another one\n");	
}

int		ft_words(char *s, char c)
{
	int		w;
	int		i;

	w = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if ((s[i] == c && s[i] != '\0') || (s[i] == '\0' && s[i - 1] != c))
			w++;
		if (s[i] == '\0')
			return (w);
		i++;
	}
	return (w);
}

t_all	*read_file(char **argv, t_all *all, int fd)
{
	char		*line;
	int			line_nb;
	t_matrix	**coords;
	int			check;

	line_nb = 0;
	check = 0;	
	coords = (t_matrix **)malloc(sizeof(t_matrix*) * all->map_y);
	while (get_next_line(fd, &line) > 0)
	{
		all->map_x = ft_words(line, ' ');
		if (line_nb != 0 && check != all->map_x)
		{
			all->map_x = -1;
			break;
		}
		coords[line_nb] = save_coords(line, line_nb, all);
		free(line);
		line_nb++;
		check = all->map_x;
	}
	all->map_y = line_nb;
	close(fd);
	all->matrix = coords;
	return (all);
}

int		main(int argc, char **argv)
{
	t_all	*all;
	int		fd;

	if (argc == 2)
	{
		all = (t_all *)malloc(sizeof(t_all));
		fd = open(argv[1], O_RDONLY);
		all = read_file(argv, all, fd);
		if (all->map_x == -1)
		{
			error_msg(2);
			return (0);
		}
		go(all);
	}
	else
		error_msg(1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:13:56 by vkarpova          #+#    #+#             */
/*   Updated: 2018/08/17 16:42:14 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include "fdf.h"

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

void    read_file(char **argv)
{
    char    *line;
    int     fd;
	t_all	all;
	int		line_nb;

	line_nb = 0;
    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
		all.max_x = ft_words(line, ' ') - 1;
//		printf("x = %d\n", all.max_x - 1);
//		ft_strsplit(line, ' ');
		free(line);
		line_nb++;
    }
	all.max_y = line_nb - 1;
	printf("max_x = %d\n", all.max_x);
	printf("max_y = %d\n", all.max_y);
}

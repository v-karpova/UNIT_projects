/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:13:56 by vkarpova          #+#    #+#             */
/*   Updated: 2018/08/17 17:00:48 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


t_matrix    **save_coords(char *line, int line_nb, t_all all)
{
    t_matrix    **coords;
    char        **split;
    int         i;

    // printf("\n\nline%d -> %s\n", line_nb, line);
    split = ft_strsplit(line, ' ');
    i = 0;
    coords = (t_matrix **)malloc(sizeof(t_matrix *) * all.map_x);
    while (split[i] != '\0')
    {
        coords[line_nb] = (t_matrix *)malloc(sizeof(t_matrix));
        coords[line_nb][i].x = i;
        coords[line_nb][i].y = line_nb;
        coords[line_nb][i].z = atoi(split[i]);
        // printf("(%d,%d,%d) ", coords[line_nb][i].x, coords[line_nb][i].y, coords[line_nb][i].z);
        i++;
    }
    // printf("\n");
    return (coords);
}


t_all    read_file(char **argv, t_all all)
{
    char        *line;
    int         fd;
	int         line_nb;
    t_matrix    **coords;
    int         check;

	line_nb = 0;
    check = 0;
    fd = open(argv[1], O_RDONLY);
    while (get_next_line(fd, &line) > 0)
    {
		all.map_x = ft_words(line, ' ');
        if (line_nb != 0 && check != all.map_x)
        {
            all.map_x = -1;
            break;
        }
        coords = save_coords(line, line_nb, all);
		free(line);
		line_nb++;
        check = all.map_x;
    }
    all.map_y = line_nb;
    close(fd);
    // printf("map_x = %d,map_y = %d\n", all.map_x, all.map_y);
    return (all);

   

}

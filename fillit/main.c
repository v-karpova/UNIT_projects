/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:18:08 by vkarpova          #+#    #+#             */
/*   Updated: 2018/06/07 20:42:19 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	fd = 0;
	list = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)))
		{
			if ((map_read(fd, list)) == 0)
				write(1, "error\n", 6);
		}
	}
	return (0);
}

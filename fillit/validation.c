/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:23:01 by omaslova          #+#    #+#             */
/*   Updated: 2018/06/07 21:15:27 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**arr_fill(char *buff)
{
	char	**arr;
	int		dot;
	int		i;
	int		j;

	i = 0;
	dot = 0;
	arr = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		arr[i] = (char *)malloc(sizeof(char) * 4);
		j = 0;
		while (j < 4 && (*buff == '#' || *buff == '.') && *buff != '\n')
		{
			if (*buff == '.')
				dot++;
			arr[i][j] = *buff++;
			j++;
		}
		buff++;
		i++;
	}
	if (j < 4 || dot != 12)
		return (NULL);
	return (arr);
}

int		check(char **arr)
{
	int i;
	int j;
	int chain;

	i = -1;
	chain = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4 && chain < 9)
		{
			if (i < 3 && j < 4 && arr[i][j] == '#' && arr[i + 1][j] == '#')
				chain += 2;
			if (i < 4 && j < 3 && arr[i][j] == '#' && arr[i][j + 1] == '#')
				chain += 2;
		}
	}
	if (chain == 6 || chain == 8)
		return (1);
	return (0);
}

t_list	*map_check(char **arr, char c)
{
	int		i;
	int		j;
	int		cntr;
	t_list	*tmp;

	i = -1;
	cntr = 0;
	tmp = NULL;
	if (arr)
	{
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (arr[i][j] == '#')
					cntr++;
		}
		if (cntr == 4)
		{
			arr = move(arr);
			if (check(arr) == 1)
				tmp = create_node(arr, c);
		}
	}
	return (tmp);
}

void	tetris(t_list *list)
{
	int		dim;
	t_list	*tmp;
	char	**tetris;

	dim = 2;
	tmp = list;
	tetris = empty_map(dim);
	while ((make_map(tetris, tmp, dim)) == 0)
	{
		dim++;
		tetris = empty_map(dim);
		tmp = list;
	}
	print(tetris, dim);
}

int		map_read(int fd, t_list *list)
{
	char	buff[21];
	int		check;
	char	c;
	t_list	*tmp;

	c = 65;
	tmp = NULL;
	while (c < 92 && (check = read(fd, buff, 20)))
	{
		if ((tmp = map_check(arr_fill(buff), c)) == NULL || check != 20)
			return (0);
		push_back(&list, tmp, c);
		c++;
		read(fd, buff, 1);
	}
	if (*buff == '\n' || !list || c >= 92)
		return (0);
	tetris(list);
	return (1);
}

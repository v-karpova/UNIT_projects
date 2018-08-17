/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:55:55 by vkarpova          #+#    #+#             */
/*   Updated: 2018/06/07 20:41:17 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**empty_map(int dim)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * dim);
	while (i < dim)
	{
		map[i] = (char *)malloc(sizeof(char) * dim);
		j = 0;
		while (j < dim)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

char	**delete(char **tetris, char c, int dim)
{
	int i;
	int j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			if (tetris[i][j] == c)
				tetris[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tetris);
}

void	insert(char **tetris, t_list *list, int *indx)
{
	int a;

	a = 0;
	while (a < 4)
	{
		tetris[indx[0] + list->arr[a][0]][indx[1] + list->arr[a][1]] = list->c;
		a++;
	}
}

int		check_point(char **tetris, t_list *list, int *indx, int dim)
{
	int a;
	int i;
	int j;

	a = 0;
	while (indx[0] < dim)
	{
		while (a < 4 && indx[1] < dim)
		{
			i = indx[0] + list->arr[a][0];
			j = indx[1] + list->arr[a][1];
			if (i < dim && j < dim && tetris[i][j] == '.')
				a++;
			else
			{
				a = 0;
				indx[1]++;
			}
			if (a == 4)
				return (1);
		}
		indx[1] = 0;
		indx[0]++;
	}
	return (0);
}

int		make_map(char **tetris, t_list *list, int dim)
{
	t_list	*tmp;
	int		indx[2];

	indx[0] = 0;
	tmp = list;
	if (!tmp)
		return (1);
	while (indx[0] < dim)
	{
		indx[1] = 0;
		while (indx[1] < dim)
		{
			if ((check_point(tetris, tmp, indx, dim)) == 1)
			{
				insert(tetris, tmp, indx);
				if ((make_map(tetris, tmp->next, dim)) == 1)
					return (1);
				else
					delete(tetris, tmp->c, dim);
			}
			indx[1]++;
		}
		indx[0]++;
	}
	return (0);
}

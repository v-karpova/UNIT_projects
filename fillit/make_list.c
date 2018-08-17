/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:31:49 by vkarpova          #+#    #+#             */
/*   Updated: 2018/06/07 20:39:28 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print(char **arr, int dim)
{
	int i;
	int j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

t_list	*create_node(char **tetris, char c)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		a;

	i = -1;
	a = -1;
	tmp = NULL;
	if ((tmp = (t_list *)malloc(sizeof(t_list))))
	{
		tmp->tetriminos = tetris;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				if (tetris[i][j] != '.')
				{
					tmp->arr[++a][0] = i;
					tmp->arr[a][1] = j;
				}
		}
		tmp->c = c;
		tmp->next = NULL;
	}
	return (tmp);
}

void	push_back(t_list **list, t_list *elem, char c)
{
	t_list *tmp;

	tmp = *list;
	if (!(*list))
		*list = create_node(elem->tetriminos, c);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

void	find_coords(char **arr, int *min_i, int *min_j)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] != '.' && i < *min_i)
				*min_i = i;
			if (arr[i][j] != '.' && j < *min_j)
				*min_j = j;
		}
	}
}

char	**move(char **arr)
{
	int i;
	int j;
	int min_i;
	int min_j;

	min_i = 4;
	min_j = 4;
	find_coords(arr, &min_i, &min_j);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] != '.' && (min_i > 0 || (min_i == 0 && min_j > 0)))
			{
				arr[i - min_i][j - min_j] = arr[i][j];
				arr[i][j] = '.';
			}
			j++;
		}
		i++;
	}
	return (arr);
}

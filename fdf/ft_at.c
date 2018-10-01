/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkarpova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:13:01 by vkarpova          #+#    #+#             */
/*   Updated: 2018/09/27 14:14:48 by vkarpova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		work_while(int i)
{
	int	base_16;
	int c;

	base_16 = 1;
	c = 6 - i;
	while (c > 0)
	{
		base_16 = base_16 * 16;
		c--;
	}
	return (base_16);
}

static int		ft_add_to_atoi(const char *str, int i, int num)
{
	int		base_16;
	int		n;
	char	*base;
	char	*base1;

	base = "0123456789ABCDEF";
	base1 = "0123456789abcdef";
	base_16 = work_while(i);
	if (str[i] >= '0' && str[i] <= '9')
		num = num + ((str[i] - '0') * base_16);
	else if (str[i] >= 'A' && str[i] <= 'F')
	{
		n = 0;
		while (base[n] != str[i])
			n++;
		num = num + (n * base_16);
	}
	else
	{
		n = 0;
		while (base1[n] != str[i])
			n++;
		num = num + (n * base_16);
	}
	return (num);
}

int				ft_atoi_base_16(const char *str)
{
	int			x;
	size_t		i;
	long long	num;

	x = 1;
	i = 0;
	num = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			&& str[i] != '\0')
		i++;
	(str[i] == '-') ? x = -1 : 0;
	(str[i] == '+' || str[i] == '-') ? i++ : 0;
	while ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] <= 'F')
			|| (str[i] >= 'a' && str[i] <= 'f'))
	{
		num = ft_add_to_atoi(str, i, num);
		i++;
	}
	(num < 0 && x == -1) ? num = 0 : 0;
	(num < 0 && x == 1) ? num = -1 : 0;
	return ((int)(num * x));
}

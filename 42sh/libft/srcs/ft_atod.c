/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 18:05:27 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:46:48 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int		ft_pow(int a, int b)
{
	int		i;
	int		tmp;

	if (b == 0)
		return (1);
	i = 1;
	tmp = a;
	while (i < b)
	{
		a = a * tmp;
		i++;
	}
	return (a);
}

double			ft_atod(char *s)
{
	char	**t;
	double	a;
	double	b;
	int		i;
	int		sign;

	sign = (s[0] == '-' ? -1 : 1);
	i = 0;
	t = ft_strsplit(s, '.');
	a = (double)ft_atoi(t[0]);
	if (t[1])
	{
		while (t[1][i])
		{
			b = sign * ((double)(t[1][i]) - 48) / ft_pow(10, i + 1);
			a = a + b;
			i++;
		}
	}
	return (a);
}

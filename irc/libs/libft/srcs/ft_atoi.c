/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:36:32 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:47:35 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_isok(char c)
{
	if (ft_isdigit(c) == 1 || c == '+' || c == '-')
		return (1);
	return (0);
}

int				ft_atoi(const char *s)
{
	int		sign;
	int		x;

	x = 0;
	sign = 1;
	while ((*s < 14 && *s > 8) || *s == 32)
		s++;
	if (ft_isok(*s) == 0)
		return (0);
	else if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s && ft_isdigit(*s) == 1)
	{
		x = x * 10 + *s - 48;
		s++;
	}
	return (x * sign);
}

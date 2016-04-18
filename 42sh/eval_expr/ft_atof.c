/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 11:36:16 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:42:47 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		ft_get_sign(char *s, int i, int *sign)
{
	while (s[i] && s[i] == '+')
		++i;
	if (s[i] == '-')
	{
		while (s[i] && s[i] == '-')
			++i;
		*sign = -1;
	}
	return (i);
}

static int		ft_get_point(char *s, int i, double *res, int *e)
{
	int		k;

	k = 0;
	while (ft_is_digit(s[i]) && s[i])
	{
		*res = *res * 10.0 + (double)(s[i] - '0');
		k--;
		++i;
	}
	*e = k;
	return (i);
}

static int		ft_get_exposant(char *s, int i, int *e)
{
	int	k;
	int	sign;

	k = 0;
	sign = 1;
	i = ft_get_sign(s, i, &sign);
	while (s[i] && ft_is_digit(s[i]))
	{
		k = k * 10 + (s[i] - '0');
		++i;
	}
	k = k * sign;
	*e = *e + k;
	return (i);
}

static int		ft_get_double(char *s, int i, double *res)
{
	while (ft_is_digit(s[i]) && s[i])
	{
		*res = *res * 10.0 + (double)(s[i] - '0');
		++i;
	}
	return (i);
}

double			ft_atof(char *s)
{
	double	res;
	int		e;
	int		sign;
	int		i;

	res = 0.0;
	e = 0;
	sign = 1;
	i = ft_get_sign(s, 0, &sign);
	i = ft_get_double(s, i, &res);
	if (s[i] == '.')
		i = ft_get_point(s, ++i, &res, &e);
	if (s[i] == 'e' || s[i] == 'E')
		i = ft_get_exposant(s, ++i, &e);
	while (e > 0)
	{
		res *= 10.0;
		--e;
	}
	while (e < 0)
	{
		res *= 0.1;
		++e;
	}
	return (res * sign);
}

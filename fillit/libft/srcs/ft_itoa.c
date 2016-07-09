/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:07:10 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:32:36 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		mal_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static int		pow_len(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static int		power(int n, int pow)
{
	int		a;

	a = n;
	if (pow == 0)
		return (1);
	while (pow > 1)
	{
		a = n * a;
		pow--;
	}
	return (a);
}

static void		fill(char *str, int *i, int *n, int *len)
{
	while (*len >= 0)
	{
		str[*i] = *n / power(10, *len) + 48;
		(*i)++;
		*n = *n % power(10, *len);
		if (*n == 0)
		{
			while (*len)
			{
				str[*i] = 48;
				(*i)++;
				(*len)--;
			}
		}
		(*len)--;
	}
	str[*i] = '\0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	if (n == -2147483648)
	{
		str = ft_strnew(11);
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	i = 0;
	len = pow_len(n);
	str = (char *)ft_memalloc(sizeof(char) * mal_size(n) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		n = -n;
		i++;
	}
	fill(str, &i, &n, &len);
	return (str);
}

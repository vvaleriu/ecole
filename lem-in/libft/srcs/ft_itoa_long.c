/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:07:10 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:06:52 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_fill_itoa_long(char *str, long int n, int i)
{
	if (n >= 0)
		while (i >= 0)
		{
			str[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
	else
	{
		n = -n;
		while (i > 0)
		{
			str[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
		str[i] = '-';
	}
}

char			*ft_itoa_long(long int n)
{
	char		*str;
	long int	nt;
	int			i;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	i = 0;
	nt = (n > 0 ? n : -n);
	while (nt > 0)
	{
		i++;
		nt /= 10;
	}
	i = (i == 0 ? 1 : i);
	i = (n >= 0 ? i : i + 1);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	ft_fill_itoa_long(str, n, i - 1);
	return (str);
}

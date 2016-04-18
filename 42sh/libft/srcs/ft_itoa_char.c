/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:07:10 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:14:56 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_fill_itoa_char(char *str, char n, int i)
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

char			*ft_itoa_char(char n)
{
	char	*str;
	char	nt;
	int		i;

	if (n == CHAR_MIN)
		return (ft_strdup("-128"));
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
	ft_fill_itoa_char(str, n, i - 1);
	return (str);
}

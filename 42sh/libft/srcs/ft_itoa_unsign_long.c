/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsign_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:07:10 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:07:26 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_fill_itoa_unsign_long(char *str, unsigned long int n, int i)
{
	while (i >= 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
}

char			*ft_itoa_unsign_long(unsigned long int n)
{
	char				*str;
	unsigned long int	nt;
	int					i;

	i = 0;
	nt = n;
	while (nt > 0)
	{
		i++;
		nt /= 10;
	}
	i = (i == 0 ? 1 : i);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	ft_fill_itoa_unsign_long(str, n, i - 1);
	return (str);
}

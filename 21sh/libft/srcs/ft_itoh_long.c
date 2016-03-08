/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:15:15 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/04 12:31:09 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_fill_itoh_long(char *tab)
{
	tab[0] = '0';
	tab[1] = '1';
	tab[2] = '2';
	tab[3] = '3';
	tab[4] = '4';
	tab[5] = '5';
	tab[6] = '6';
	tab[7] = '7';
	tab[8] = '8';
	tab[9] = '9';
	tab[10] = 'a';
	tab[11] = 'b';
	tab[12] = 'c';
	tab[13] = 'd';
	tab[14] = 'e';
	tab[15] = 'f';
}

char	*ft_itoh_long(long unsigned int n)
{
	char	hex[16];
	char	*ret;
	int		len;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	ret = ft_strnew(10);
	ft_fill_itoh_long(hex);
	while (n != 0)
	{
		ret[len] = hex[n & 0x000F];
		len++;
		n = (n >> 4);
	}
	ft_strrev(ret);
	return (ret);
}

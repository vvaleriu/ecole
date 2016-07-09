/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh_cap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 23:13:18 by vincent           #+#    #+#             */
/*   Updated: 2015/02/04 12:30:14 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_fill_itoh_cap(char *tab)
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
	tab[10] = 'A';
	tab[11] = 'B';
	tab[12] = 'C';
	tab[13] = 'D';
	tab[14] = 'E';
	tab[15] = 'F';
}

char	*ft_itoh_cap(unsigned int n)
{
	char	hex[16];
	char	*ret;
	int		len;

	if (!n)
		return (ft_strdup("0"));
	len = 0;
	ret = ft_strnew(16);
	ft_fill_itoh_cap(hex);
	while (n != 0)
	{
		ret[len] = hex[n & 0x000F];
		len++;
		n = (n >> 4);
	}
	ft_strrev(ret);
	return (ret);
}

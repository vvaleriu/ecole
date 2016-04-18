/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:31:49 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:15:55 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_otoa_short(unsigned short int n)
{
	char				*p;
	int					size;
	unsigned short int	x;

	x = n;
	size = 0;
	while (x > 7)
	{
		x = x / 8;
		size++;
	}
	p = (char *)ft_memalloc(sizeof(p) * (size + 1));
	if (p)
	{
		p[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			p[size] = 48 + x;
			n = n / 8;
			size--;
		}
	}
	return (p);
}

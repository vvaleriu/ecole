/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 17:29:13 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <wchar.h>

static int		ft_putwchar_last(unsigned int c)
{
	int i;

	i = 0;
	i += ft_putchar(0xF0 | (c >> 18));
	i += ft_putchar(0x80 | ((c >> 12) & 0x3F));
	i += ft_putchar(0x80 | ((c >> 6) & 0x3F));
	i += ft_putchar(0x80 | (c & 0x3F));
	return (i);
}

int				ft_putwchar(wchar_t wc)
{
	unsigned int	c;
	int				i;

	c = wc;
	i = 0;
	if (c < 0x80)
		i += ft_putchar(c);
	else if (c < 0x800)
	{
		i += ft_putchar(0xC0 | (c >> 6));
		i += ft_putchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		i += ft_putchar(0xE0 | (c >> 12));
		i += ft_putchar(0x80 | ((c >> 6) & 0x3F));
		i += ft_putchar(0x80 | (c & 0x3F));
	}
	else if (c < 0x200000)
		i += ft_putwchar_last(c);
	return (i);
}

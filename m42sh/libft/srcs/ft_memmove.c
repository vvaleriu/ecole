/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:29:17 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:54:49 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dst_e;
	const char	*src_e;

	dst_e = (char *)dst;
	src_e = (char *)src;
	if (src_e > dst_e)
		ft_memcpy(dst, src, n);
	else
	{
		dst_e = dst_e + n - 1;
		src_e = src_e + n - 1;
		while (n--)
		{
			*dst_e-- = *src_e--;
		}
	}
	return (dst);
}

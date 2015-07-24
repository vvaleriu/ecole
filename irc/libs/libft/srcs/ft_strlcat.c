/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:37:42 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/11/27 17:18:53 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t		size_d;
	int			to_cat;
	int			ret;

	ret = ft_strlen(src) + ft_strlen(dst);
	size_d = ft_strlen(dst);
	if (len <= size_d + 1)
		return (ft_strlen(src) + len);
	to_cat = len - size_d;
	while (*src && to_cat > 1)
	{
		dst[size_d] = *src;
		src++;
		size_d++;
		to_cat--;
	}
	dst[size_d] = '\0';
	return (ret);
}

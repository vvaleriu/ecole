/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:53:45 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/20 22:23:13 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (*dest)
	{
		dest++;
		i++;
	}
	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
		i++;
	}
	*dest = '\0';
	return (dest - i);
}

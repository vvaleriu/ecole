/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:52:55 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/09 00:04:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	if (dest && src)
	{
		while (*src)
		{
			*dest = *src;
			src++;
			dest++;
			i++;
		}
		*dest = '\0';
		return (dest - i);
	}
	return (NULL);
}

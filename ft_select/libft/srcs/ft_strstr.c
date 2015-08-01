/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:30:12 by vvaleriu          #+#    #+#             */
/*   Updated: 2014/03/27 19:04:25 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int	k;

	k = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1)
	{
		while (*s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
			k++;
		}
		if (*s2 == '\0')
			return ((char *)s1 - k);
		else
		{
			s2 = s2 - k;
			s1 = s1 - k;
			k = 0;
		}
		s1++;
	}
	return (NULL);
}

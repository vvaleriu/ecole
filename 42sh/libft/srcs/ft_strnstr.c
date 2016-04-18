/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:30:12 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:49:44 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		k;

	k = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && n)
	{
		while (*s2 != '\0' && *s1 == *s2 && n)
		{
			s1++;
			s2++;
			k++;
			n--;
		}
		if (*s2 == '\0')
			return ((char *)s1 - k);
		else
		{
			s2 = s2 - k;
			s1 = s1 - k + 1;
			n = n + k - 1;
			k = 0;
		}
	}
	return (NULL);
}

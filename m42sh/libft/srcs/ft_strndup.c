/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:16:15 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/02 16:39:51 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * n + 1);
	if (!s2)
		return (NULL);
	while (n && s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
		n--;
	}
	while (n)
	{
		s2[i] = '\0';
		i++;
		n--;
	}
	s2[i] = '\0';
	return (s2);
}

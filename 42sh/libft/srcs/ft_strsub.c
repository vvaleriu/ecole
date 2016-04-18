/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:11:15 by vvaleriu          #+#    #+#             */
/*   Updated: 2014/03/27 19:03:42 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (len)
	{
		ret[i] = s[start];
		i++;
		start++;
		len--;
	}
	ret[i] = '\0';
	return (ret);
}

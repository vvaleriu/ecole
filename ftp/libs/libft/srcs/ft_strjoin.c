/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:24:50 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/11/28 11:47:58 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	char	*ret;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ret = ft_strnew(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (*s1)
	{
		ret[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ret[i] = *s2;
		s2++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

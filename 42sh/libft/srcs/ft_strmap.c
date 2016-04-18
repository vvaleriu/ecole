/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/11/28 11:32:22 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		ret = ft_strnew(ft_strlen(s) + 1);
		while (*s)
		{
			*ret = f(*s);
			ret++;
			s++;
			i++;
		}
		*ret = '\0';
		return (ret - i);
	}
	return (NULL);
}

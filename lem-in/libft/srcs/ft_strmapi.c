/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:50:51 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		ret = ft_strnew(ft_strlen(s) + 1);
		while (s[i])
		{
			*ret = f(i, s[i]);
			ret++;
			i++;
		}
		*ret = '\0';
		return (ret - i);
	}
	return (NULL);
}

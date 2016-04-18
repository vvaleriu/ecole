/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:37:35 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/05 13:05:37 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

wchar_t		*ft_wstrdup(const wchar_t *s1)
{
	wchar_t	*s2;
	int		i;

	i = 0;
	s2 = (wchar_t *)ft_memalloc(sizeof(wchar_t) * ft_wstrlen(s1) + 1);
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

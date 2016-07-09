/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:16:15 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/05 13:45:27 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

wchar_t		*ft_wstrndup(const wchar_t *s1, size_t n)
{
	wchar_t	*s2;
	int		i;

	i = 0;
	s2 = (wchar_t *)ft_memalloc(sizeof(wchar_t) * n + 1);
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

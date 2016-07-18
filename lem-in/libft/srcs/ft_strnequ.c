/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:02:37 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/19 16:16:07 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && *s1 == *s2 && n > 1)
		{
			s1++;
			s2++;
			n--;
		}
		if (*s1 == *s2)
			return (1);
		else
			return (0);
	}
	return (-1);
}

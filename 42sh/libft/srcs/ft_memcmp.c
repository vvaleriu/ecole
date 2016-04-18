/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:12:02 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:56:01 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*t1;
	char	*t2;

	t1 = (char *)s1;
	t2 = (char *)s2;
	if (n == 0)
		return (0);
	while (*t1 == *t2 && n-- > 1)
	{
		t1++;
		t2++;
	}
	return (*(unsigned char *)t1 - *(unsigned char *)t2);
}

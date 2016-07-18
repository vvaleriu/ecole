/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:42:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:55:14 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memdup(const void *s1, size_t n)
{
	void			*ret;
	char			*ret_e;
	const char		*s1_e;

	ret = (void *)ft_memalloc(n);
	ret_e = (char *)ret;
	s1_e = (char *)s1;
	while (n)
	{
		*ret_e = *s1_e;
		ret_e++;
		s1_e++;
		n--;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:03:50 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:56:47 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;
	char	*tmp;

	ret = (void *)malloc(size);
	if (!ret)
		return (NULL);
	tmp = ret;
	while (size)
	{
		*tmp = 0;
		tmp++;
		size--;
	}
	return (ret);
}

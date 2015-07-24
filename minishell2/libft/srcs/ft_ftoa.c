/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 10:49:21 by vincent           #+#    #+#             */
/*   Updated: 2015/02/10 14:05:10 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_ftoa(float n)
{
	char	*ret;
	char	*tmp;
	int		it;
	float	dec;

	it = (int)n;
	dec = ((n - it) * 1000000 > 0 ? (n - it) * 1000000 : -(n - it) * 1000000);
	tmp = ft_itoa(it);
	ret = ft_strjoin(tmp, ".");
	ft_strdel(&tmp);
	tmp = ret;
	ret = ft_strjoin(ret, ft_itoa((int)dec));
	ft_strdel(&tmp);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:36:10 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/11/24 13:57:28 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strrev(char *s)
{
	char	c;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s) - 1;
	while (i < len)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
		i++;
		len--;
	}
}

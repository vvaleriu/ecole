/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:36 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/22 16:24:18 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_putendl(char const *s)
{
	int		i;

	i = 0;
	while (*s)
	{
		ft_putchar(*s);
		s++;
		i++;
	}
	ft_putchar('\n');
	return (i + 1);
}

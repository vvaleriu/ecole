/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 17:17:05 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 15:34:28 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

char	*ft_readlink(char *path)
{
	int			rd;
	char		*buf;

	buf = (char *) ft_memalloc(257);
	rd = readlink(path, buf, 257);
	buf[rd] = '\0';
	return (buf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:26:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/19 17:16:33 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	Retourne le nombre de mots de la chaine a separer
*/

static int		ct_wd(const char *s, char c)
{
	int		nb;

	nb = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			s++;
		nb = (*(s - 1) != c ? nb + 1 : nb);
	}
	return (nb);
}

/*
**	Retourne le nombre de caracteres incluant les \0
*/

static int		ct_c(const char *s, char c)
{
	int		nb;

	nb = 0;
	while (*s)
	{
		if (*s != c)
			nb++;
		s++;
	}
	return (nb);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**ret;
	char	*str;
	int		i;

	i = ct_wd(s, c);
	ret = (char **)ft_memalloc(sizeof(*ret) * (i + 1));
	str = (char *)ft_memalloc(sizeof(*str) * ct_c(s, c) + i);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		ret[i++] = (*s ? str : '\0');
		while (*s && *s != c)
			*str++ = *s++;
		if (*s)
			*str++ = '\0';
	}
	return (ret);
}

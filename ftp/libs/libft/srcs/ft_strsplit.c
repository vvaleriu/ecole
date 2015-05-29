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

static void		fill(const char *s, int *t, char **ret, char *tmp)
{
	while (*s)
	{
		ret[L] = tmp;
		while (*s != t[4] && *s)
			*tmp++ = *s++;
		tmp++;
		while (*s == t[4] && *s)
			s++;
		L++;
	}
}

static void		filltab(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
	t[4] = 0;
}

char			**ft_strsplit(const char *s, char c)
{
	int		t[5];
	char	**ret;
	char	*tmp;

	filltab(t);
	while (*s == c)
		s++;
	while (s[I])
	{
		while (s[I] != c && s[I])
		{
			I++;
			J++;
		}
		while (s[I] == c && s[I])
			I++;
		K++;
	}
	ret = (char **)ft_memalloc(sizeof(char *) * K + 1);
	tmp = (char *)ft_memalloc(sizeof(char) * J + K);
	t[4] = (int)c;
	fill(s, t, ret, tmp);
	return (ret);
}

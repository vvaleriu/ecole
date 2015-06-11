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

static int		ct_wd(const char *s, char c)
{
	int		nb;

	nb = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		nb++;
		while (*s != c)
			s++;
		while (*s == c)
			s++;
	}
	ft_putendl(ft_itoa(nb));
	return (nb);
}

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
	ft_putendl(ft_itoa(nb));
	return (nb);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**ret;
	char	*str;
	int		i;

	i = 0;
	ret = (char **)ft_memalloc(sizeof(*ret) * ct_wd(s, c) + 1);
	str = (char *)ft_memalloc(sizeof(*str) * ct_c(s, c) + ct_wd(s, c));
	while (*s)
	{
		ret[i++] = str;
		while (*s != c)
			*(str++) = *(s++);
		*(str++) = '\0';
		while (*s == c)
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

/*
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
*/
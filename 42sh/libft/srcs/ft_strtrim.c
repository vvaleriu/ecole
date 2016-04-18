/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 09:35:34 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 11:01:31 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		emp_start(const char *s)
{
	int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	else
		return (i);
}

static int		emp_end(const char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (i <= 0)
		return (0);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	return (i + 1);
}

char			*ft_strtrim(const char *s)
{
	char	*ret;
	int		a;
	int		i;

	if (s == NULL)
		return (NULL);
	a = emp_start(s);
	i = 0;
	ret = (char *)ft_memalloc(sizeof(char) * (emp_end(s) - a) + 2);
	if (!ret)
		return (NULL);
	if (emp_end(s) == 0)
	{
		*ret = '\0';
		return (ret);
	}
	while (a < emp_end(s))
	{
		ret[i] = s[a];
		i++;
		a++;
	}
	ret[i] = '\0';
	return (ret);
}

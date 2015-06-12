/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:23:13 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 16:09:14 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_resize(void *ptr, size_t n)
{
	void	*fresh;

	if (n == 0)
	{
		free(ptr);
		ptr = NULL;
	}
	if (ptr == NULL)
	{
		fresh = ft_strnew(n);
		return (fresh);
	}
	fresh = ft_strnew(n);
	ft_strncpy(fresh, ptr, n);
	return (fresh);
}

void		ft_readline(int const fd, int *ret, char **buff, char **tmp)
{
	while (*ret > 0)
	{
		*ret = read(fd, *buff, BUFF_SIZE);
		if (*ret != -1)
		{
			*tmp = ft_strncat(ft_resize(*tmp, BUFF_SIZE + ft_strlen(*tmp)), \
					*buff, *ret);
			if (ft_strchr(*tmp, '\n'))
				break ;
		}
	}
}

int			get_next_line(int const fd, char **line)
{
	static char		*tmp;
	char			*buff;
	int				ret;
	int				i;

	i = 0;
	ret = 1;
	if (fd < 0 || BUFF_SIZE < 0 || line == NULL)
		return (-1);
	if (tmp == NULL)
		tmp = ft_strnew(1);
	buff = ft_strnew(BUFF_SIZE);
	ft_readline(fd, &ret, &buff, &tmp);
	while (tmp[i] != '\n' && tmp[i])
		i += 1;
	*line = ft_strsub(tmp, 0, i);
	if (!line)
		free(line);
	while (*tmp != '\n' && *tmp)
		tmp += 1;
	if (ret == 0 && !*line[0] && !ft_strchr(tmp, '\n'))
		return (0);
	tmp += 1;
	return (1);
}

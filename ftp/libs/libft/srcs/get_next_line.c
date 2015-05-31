/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:02:35 by vincent           #+#    #+#             */
/*   Updated: 2015/03/03 16:01:33 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**static void		reset_struct(t_str_prop *prop)
**{
**	prop->char_rd = -1;
**	prop->file = NULL;
**	prop->tmp = NULL;
**}
**  function return 2 when reachs EOF
*/

static int		set_pointer(t_str_prop *prop, char *end, char **line)
{
	*end = '\0';
	*line = prop->file;
	prop->tmp = prop->file;
	prop->file = ft_strdup(end + 1);
	return (1);
}

static int		end_of_file(t_str_prop *prop, char *end)
{
	ft_strdel(&(prop->file));
	ft_strdel(&(prop->tmp));
	ft_strdel(&end);
	return (-2);
}

int				get_next_line(int const fd, char **line)
{
	static t_str_prop	prop = {-2, NULL, NULL};
	char				*buf;
	char				*end;

	buf = (char *)ft_memalloc(sizeof(char) * GNL_BUFFER + 1);
	if (fd < 0 || GNL_BUFFER < 1 || !buf)
		return (-1);
	if (prop.char_rd == -2)
		prop.file = ft_strnew(0);
	ft_strdel(&prop.tmp);
	while ((end = ft_strchr(prop.file, '\n')) == NULL && prop.char_rd != 0)
	{
		prop.char_rd = read(fd, buf, GNL_BUFFER);
		if (!prop.char_rd)
			return (end_of_file(&prop, end));
		buf[prop.char_rd] = '\0';
		prop.tmp = prop.file;
		prop.file = ft_strjoin(prop.file, buf);
		ft_strdel(&prop.tmp);
	}
	if (end)
		return (set_pointer(&prop, end, line));
	*line = prop.file;
	return (0);
}

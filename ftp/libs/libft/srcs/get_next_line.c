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
**  function return -2 when reachs EOF
**
** (end = ft_strchr(prop.file, '\n')) == NULL && prop.char_rd != 0
** -> Tant qu'on ne trouve pas de \n et que le nombre de caract lus est > 0
** prop.char_rd = read(fd, buf, GNL_BUFFER);
** -> On lit
** if (!prop.char_rd)
**			return (end_of_file(&prop, line));
** -> Si on ne lit rien, on envoie -2 (fin de la lecture), on remet le ptr line
** 		ou il faut et on efface tmp
**  buf[prop.char_rd] = '\0';
** 	prop.tmp = prop.file;
** 	prop.file = ft_strjoin(prop.file, buf);
**	ft_strdel(&prop.tmp);
** -> on met le \0 on garde l'ancien malloc qql pour le free plus tard
** 	on join ce qu'on a lu precedemment a ce qu'on vient de lire et on efface
**	l'ancien malloc conserve dans tmp;
**  on reboucle et si on trouve un \n, alors on rentre dans set_pointer
**	On transforme le \n en \0, on fait pointer line sur le debut de la chaine,
**	on met tmp sur le debut de la chaine et on fait une copie de ce qui se
**	trouve apres le \n pour pouvoir le reutiliser et le remttre au debut de
**	la prochaine chaine qu'on lira.
*/

/*
**	Retourne le nombre de mots de la chaine a separer
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

/*
static int		set_pointer(t_str_prop *prop, char *end, char **line)
{
	*end = '\0';
	*line = prop->file;
	prop->tmp = prop->file;
	prop->file = ft_strdup(end + 1);
	return (1);
}

static int		end_of_file(t_str_prop *prop, char **line)
{
	*line = prop->file;
	ft_strdel(&(prop->tmp));
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
	ft_strdel(&prop.tmp);
	while ((end = ft_strchr(prop.file, '\n')) == NULL && prop.char_rd != 0)
	{
		prop.char_rd = read(fd, buf, GNL_BUFFER);
		if (!prop.char_rd)
			return (end_of_file(&prop, line));
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

*/
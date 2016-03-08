/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:02:35 by vincent           #+#    #+#             */
/*   Updated: 2016/03/08 15:11:46 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

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
**
**			end_of_file(t_str_prop *p, char **line)	
**
** p->rd = -3 signifie qu'on a finit de le fichier mais que celui ci ne prend
** pas de \n final. On renvoit donc la chaine mais on met le marqueur a -3
** ce qui fait qu'a la prochaine entree on va quitter et renvoyer 0 directement
*/

static int		end_of_file(t_str_prop *p, char **line)
{
	ft_strdel(&(p->buf));
	*line = p->file;
	if (ft_strlen(p->file))
	{
		p->rd = -3;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_str_prop	p = {-2, NULL, NULL, NULL, NULL};

	if (p.rd == -3)
		return (0);
	p.buf = (p.rd == -2 ? (char *)malloc(sizeof(char) * GNL_BUFFER + 1) : p.buf);
	if (fd < 0 || GNL_BUFFER < 1 || !p.buf)
		return (-1);
	ft_strdel(&p.tmp);
	while ((p.end = ft_strchr(p.file, '\n')) == NULL && p.rd != 0)
	{
		ft_bzero((void *)p.buf, GNL_BUFFER + 1);
		p.rd = read(fd, p.buf, GNL_BUFFER);
		if (!p.rd)
			return (end_of_file(&p, line));
		p.tmp = p.file;
		p.file = ft_strjoin(p.file, p.buf);
		ft_strdel(&p.tmp);
	}
	*p.end = '\0';
	*line = p.tmp = p.file;
	p.file = ft_strdup(p.end + 1);
	return (1);
}

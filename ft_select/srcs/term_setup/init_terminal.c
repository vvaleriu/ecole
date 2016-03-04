/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 12:04:41 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** On va utiliser ft_strncmp pour identifier la sequence capturee
** a celle enregistrer pour chaque touche.
** Comme la taille de la sequence a comparer differe selon la touche,
** on mesure la taille de la sequence pour un faire strncmp de la bonne taille
*/

static void	fill_keyman_tab(t_tconf *conf)
{
	int		i;

	i = -1;
	ft_strcpy(KLEFT.seq, "\033[D");
	KLEFT.f = move_cursor;
	ft_strcpy(KRIGHT.seq, "\033[C");
	KRIGHT.f = move_cursor;
	ft_strcpy(KUP.seq, "\033[A");
	KUP.f = move_cursor;
	ft_strcpy(KDOWN.seq, "\033[B");
	KDOWN.f = move_cursor;
	ft_strcpy(KSPACE.seq, "\040");
	KSPACE.f = select_item;
	ft_strcpy(KESC.seq, "\033");
	KESC.f = close_program;
	ft_strcpy(KRET.seq, "\012");
	KRET.f = close_program;
	ft_strcpy(KBKSP.seq, "\010");
	KBKSP.f = delete_item;
	ft_strcpy(KDEL.seq, "\177");
	KDEL.f = delete_item;
	while (++i < KEY_NUMBER)
		conf->keyman[i].seq_len = ft_strlen(conf->keyman[i].seq);
}

int			init_fd(int fd)
{
	fd = open(ttyname(0), O_RDWR | O_NONBLOCK);
	return (fd);
}

int			init_terminal(t_tconf *conf)
{
	fill_keyman_tab(conf);
	conf->fd = 0;
	conf->run = 1;
	conf->list = NULL;
	conf->cur_item = NULL;
	if ((conf->fd = init_fd(conf->fd)) == -1)
		return (-1);
	ioctl(0, TIOCGWINSZ, &(conf->w));
	if (load_term_prop(conf) <= 0)
		return (-1);
	return (change_term_attr(conf));
	return (1);
}
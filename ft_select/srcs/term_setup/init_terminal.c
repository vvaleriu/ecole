/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2015/08/04 17:07:08 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	fill_keyman_tab(t_tconf *conf)
{
	int		i;

	i = -1;
	ft_strcpy(KLEFT.seq, "\027[D");
	KLEFT.f = move_cursor;
	ft_strcpy(KRIGHT.seq, "\027[C");
	KRIGHT.f = move_cursor;
	ft_strcpy(KUP.seq, "\027[A");
	KUP.f = move_cursor;
	ft_strcpy(KDOWN.seq, "\027[B");
	KDOWN.f = move_cursor;
	ft_strcpy(KESC.seq, "\027");
	KESC.f = close_program;
	ft_strcpy(KRET.seq, "\013");
	KRET.f = close_program;
	ft_strcpy(KBKSP.seq, "\008");
	KBKSP.f = delete_item;
	ft_strcpy(KDEL.seq, "\127");
	KDEL.f = delete_item;
	while (++i < KEY_NUMBER)
		conf->keyman[i].seq_len = ft_strlen(conf->keyman[i].seq);
	KBKSP.seq_len = 1;
}

/*static void	fill_keyman_tab(t_tconf *conf)
{
	int		i;

	i = -1;
	ft_strcpy(KLEFT.seq, "\027[D");
	KLEFT.f = move_cursor;
	ft_strcpy(KRIGHT.seq, "\027[C");
	KRIGHT.f = move_cursor;
	ft_strcpy(KUP.seq, "\027[A");
	KUP.f = move_cursor;
	ft_strcpy(KDOWN.seq, "\027[B");
	KDOWN.f = move_cursor;
	ft_strcpy(KESC.seq, "\027");
	KESC.f = move_cursor;
	ft_strcpy(KRET.seq, "\013");
	KRET.f = move_cursor;
	ft_strcpy(KBKSP.seq, "\008");
	KBKSP.f = move_cursor;
	ft_strcpy(KDEL.seq, "\127");
	KDEL.f = move_cursor;
	while (++i < KEY_NUMBER)
		conf->keyman[i].seq_len = ft_strlen(conf->keyman[i].seq);
	KBKSP.seq_len = 1;
}*/

int			init_terminal(t_tconf *conf)
{
	fill_keyman_tab(conf);
	conf->run = 1;
	conf->list = NULL;
	conf->cur_item = NULL;
	ioctl(0, TIOCGWINSZ, &(conf->w));
	if (load_term_prop(conf) <= 0)
		return (-1);
	return (change_term_attr(conf));
	return (1);
}
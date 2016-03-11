/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/11 23:37:44 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

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
	KLEFT.f = move_to_previous_char;
	ft_strcpy(KRIGHT.seq, "\033[C");
	KRIGHT.f = move_to_next_char;
	ft_strcpy(KUP.seq, "\033[A");
	KUP.f = move_to_previous_char;
	ft_strcpy(KDOWN.seq, "\033[B");
	KDOWN.f = delete_char;
	ft_strcpy(KESC.seq, "\033");
	KESC.f = move_to_previous_char;
	ft_strcpy(KRET.seq, "\012");
	KRET.f = return_command;
	ft_strcpy(KBKSP.seq, "\177");
	KBKSP.f = erase_char;
	ft_strcpy(KDEL.seq, "\010");
	KDEL.f = delete_char;
	ft_strcpy(KHOME.seq, "\033[1");
	KHOME.f = cursor_to_origin;
	ft_strcpy(KEND.seq, "\033[4");
	KEND.f = cursor_to_origin;
	while (++i < KEY_NUMBER)
		conf->keyman[i].seq_len = ft_strlen(conf->keyman[i].seq);
}

int			init_fd(int fd)
{
	fd = open(ttyname(0), O_RDWR | O_NONBLOCK);
	return (fd);
}

int			init_terminal(t_var *var)
{
	fill_keyman_tab(var->conf);
	var->conf->fd = 0;
	var->CUR_X = 0;
	var->CUR_Y = 0;
	if ((var->conf->fd = init_fd(var->conf->fd)) == -1)
		return (-1);
	ioctl(0, TIOCGWINSZ, &(var->conf->w));
	if (load_term_prop(var->conf) <= 0)
		return (-1);
	//return (change_term_attr(var->conf));
	return (1);
}
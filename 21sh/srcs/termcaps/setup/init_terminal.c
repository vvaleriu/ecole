/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/10 15:20:42 by vvaleriu         ###   ########.fr       */
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
	KDOWN.f = move_to_next_char;
	ft_strcpy(KSPACE.seq, "\040");
	KSPACE.f = move_to_previous_char;
	ft_strcpy(KESC.seq, "\033");
	KESC.f = move_to_previous_char;
	ft_strcpy(KRET.seq, "\012");
	KRET.f = return_command;
	ft_strcpy(KBKSP.seq, "\010");
	KBKSP.f = move_to_previous_char;
	ft_strcpy(KDEL.seq, "\177");
	KDEL.f = move_to_previous_char;
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
	return (change_term_attr(var->conf));
	return (1);
}
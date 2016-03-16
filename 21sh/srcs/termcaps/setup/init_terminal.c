/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/16 11:36:03 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int 		test_input_ol(t_var *var)
{
	(void)var;
	ft_putstr_fixed("SALUT COCO fnifowefijweiof ifewjiojfweoijfiofjwwfio jfiojwfiojfwiowjwiofjiofjfiewoj");
	return (2);
}

int 		test_input_ol1(t_var *var)
{
	(void)var;
	set_str_cap("cd");
	return (2);
}
/*
** On va utiliser ft_strncmp pour identifier la sequence capturee
** a celle enregistrer pour chaque touche.
** Comme la taille de la sequence a comparer differe selon la touche,
** on mesure la taille de la sequence pour un faire strncmp de la bonne taille
*/
static void	fill_keyman_tab(t_tconf *conf)
{
	ft_strcpy(KLEFT.seq, LEFT_SEQ);
	KLEFT.f = move_to_previous_char;
	ft_strcpy(KRIGHT.seq, RIGHT_SEQ);
	KRIGHT.f = move_to_next_char;
	ft_strcpy(KUP.seq, UP_SEQ);
	KUP.f = history_next;
	ft_strcpy(KDOWN.seq, DOWN_SEQ);
	KDOWN.f = history_prev;
	ft_strcpy(KESC.seq, ESC_SEQ);
	KESC.f = move_to_previous_char;
	ft_strcpy(KRET.seq, RET_SEQ);
	KRET.f = return_command;
	ft_strcpy(KBKSP.seq, BKSP_SEQ);
	KBKSP.f = erase_char;
	ft_strcpy(KDEL.seq, DEL_SEQ);
	KDEL.f = delete_char;
	ft_strcpy(KHOME.seq, HOME_SEQ);
	KHOME.f = move_to_origin;
	ft_strcpy(KEND.seq, END_SEQ);
	KEND.f = move_to_end;
	ft_strcpy(KPGUP.seq, PGUP_SEQ);
	KPGUP.f = test_input_ol1;
	ft_strcpy(KPGDOWN.seq, PGDOWN_SEQ);
	KPGDOWN.f = test_input_ol;
}

static void	fill_keyman_tab1(t_tconf *conf)
{
	ft_strcpy(KNEXTWD.seq, NEXTWD_SEQ);
	KNEXTWD.f = move_to_next_word;
	ft_strcpy(KPREVWD.seq, PREVWD_SEQ);
	KPREVWD.f = move_to_previous_word;
	ft_strcpy(KLNUP.seq, LNUP_SEQ);
	KLNUP.f = move_to_origin;
	ft_strcpy(KLNDOWN.seq, LNDOWN_SEQ);
	KLNDOWN.f = move_to_end;
	ft_strcpy(KCLEARSCR.seq, CLEARSCR_SEQ);
	KCLEARSCR.f = cl_screen;
	ft_strcpy(KCUTST_CUR.seq, CUTST_CUR_SEQ);
	KCUTST_CUR.f = cut_from_start;
	ft_strcpy(KCUTCUR_END.seq, CUTCUR_END_SEQ);
	/*iiiiiiiiiiiii*/
	//KCUTCUR_END.f = cut_from_end;
	KCUTCUR_END.f = cut_from_start;
	ft_strcpy(KCPYST_CUR.seq, CPYST_CUR_SEQ);
	KCPYST_CUR.f = copy_from_start;
	ft_strcpy(KCPYCUR_END.seq, CPYCUR_END_SEQ);
	KCPYCUR_END.f = copy_from_end;
	ft_strcpy(KPASTE.seq, PASTE_SEQ);
	KPASTE.f = paste;
}

static void	fill_keyman_tab2(t_tconf *conf)
{
	int		i;

	i = -1;
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
	fill_keyman_tab1(var->conf);
	fill_keyman_tab2(var->conf);
	var->conf->fd = 0;
	var->CUR_X = 0;
	var->CUR_Y = 0;
	var->line.cpy = NULL;
	if ((var->conf->fd = init_fd(var->conf->fd)) == -1)
		return (-1);
	ioctl(0, TIOCGWINSZ, &(var->conf->w));
	if (load_term_prop(var->conf) <= 0)
		return (-1);
	//return (change_term_attr(var->conf));
	return (1);
}
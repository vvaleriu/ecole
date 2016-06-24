/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:13:09 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 12:13:15 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

/*
** Augmente la capacite de la ligne de commande actuelle. La nouvelle capacite
** est egale a l'ancienne plus la longeur par defaut d'une ligne de commande
** (CMD_LENGTH)
** extended_value : si 0, alors on etend la valeur avec CMD_LENGHT, sinon on
** etend la valeur avec celle de extended_value
*/

static void	extend_line_capacity(t_var *var, int extended_value)
{
	char	*new_line_buffer;

	if (!extended_value)
	{
		new_line_buffer = ft_strnew(var->line.max + CMD_LENGTH);
		var->line.max += CMD_LENGTH;
	}
	else
	{
		new_line_buffer = ft_strnew(var->line.max + extended_value);
		var->line.max += extended_value;
	}
	ft_strcpy(new_line_buffer, var->line.s);
	free(var->line.s);
	var->line.s = new_line_buffer;
}

/*
** Si la chaine est trop courte on l'agrandit. Tant qu'on n'a pas atteint la
** position du curseur, on copie chaque caractere dans la case suivane. Enfin
** on insere le caractere
** Pour finir on affiche la ligne, on ramene le curseur ou il etait et on
** avance d'une caractere.
*/

int			insert_char(t_var *var)
{
	size_t	len;
	int		initial_pos;

	if (ft_strlen(var->line.s) == var->line.max)
		extend_line_capacity(var, 0);
	len = ft_strlen(var->line.s);
	while ((int)len > var->line.pos)
	{
		var->line.s[len] = var->line.s[len - 1];
		len--;
	}
	var->line.s[var->line.pos] = var->key_buf[0];
	if (LN_POS == (int)ft_strlen(var->line.s) - 1)
		ft_putchar_cursor(var->key_buf[0]);
	else
	{
		initial_pos = LN_POS;
		set_str_cap("sc");
		set_str_cap("cd");
		ft_putstr_cursor_wrap(var);
		update_trackers(var, -(LN_POS - initial_pos));
		set_str_cap("rc");
		move_to_next_char(var);
	}
	return (2);
}

/*
** Sert a inserer une chaine de caractere dans la ligne actuelle tout en
** gardant une trace de la position sur la ligne ainsi que celle du curseur
** On cree un buffer de la taille de la somme des deux chaines
** on fait la copie dans ce nouveau buffer
** on met a jour les infos.
** On affche cette nouvelle ligne
** on place le curseur la ou il faut et on remet a jour les infos
*/

int			insert_str(t_var *var, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	set_str_cap("sc");
	tmp = ft_strnew(ft_strlen(LN_S) + len);
	ft_strncpy(tmp, LN_S, LN_POS);
	ft_strcpy(tmp + LN_POS, str);
	ft_strcpy(tmp + LN_POS + len, LN_S + LN_POS);
	ft_strdel(&(LN_S));
	LN_S = tmp;
	update_line_struct(var);
	ft_putstr_cursor_wrap(var);
	set_str_cap("rc");
	LN_POS -= len;
	CUR_POS_Y = (CUR_POS_X - len < 0 ? CUR_POS_Y - 1 : CUR_POS_Y);
	CUR_POS_X = (CUR_POS_X - len < 0 ? WIN_X + (CUR_POS_X - len) : \
		CUR_POS_X - len);
	while (len > 0)
	{
		move_to_next_char(var);
		len--;
	}
	return (2);
}

/*
** Fonction executee lors d'un appui sur retour arriere
** on bouge le curseur sur le caractere precedent
*/

int			erase_char(t_var *var)
{
	size_t			len;
	unsigned long	i;

	len = ft_strlen(var->line.s);
	move_to_previous_char(var);
	var->line.s[var->line.pos] = '\0';
	set_str_cap("dc");
	i = var->line.pos;
	while (i < len)
	{
		var->line.s[i] = var->line.s[i + 1];
		i++;
	}
	var->line.s[i] = '\0';
	return (2);
}

/*
** Fonction executee lors d'un appui sur delete / suppr
** int			delete_char(t_var *var)
** {
** 	set_str_cap("do:cr:sc");
** 	terminal_execute_mode(var->conf);
** 	set_str_cap("rc");
** 	print_trackers_status(var);
** 	set_str_cap("sc");
** 	terminal_input_mode(var->conf);
** 	set_str_cap("rc");
** 	set_str_cap("sc");
** 	CUR_POS_X = PROMPT_LEN;
** 	CUR_POS_Y = 0;
** 	if (ft_strlen(LN_S))
** 	{
** 		ft_putstr_cursor(LN_S);
** 		update_line_struct(var);
** 		LN_POS = ft_strlen(LN_S);
** 	}
** 	return (2);
** }
*/

int			delete_char(t_var *var)
{
	int		initial_pos;

	if (move_to_next_char(var) == 2)
		erase_char(var);
	if ((int)ft_strlen(LN_S + LN_POS) >= WIN_X - CUR_POS_X)
	{
		initial_pos = LN_POS;
		set_str_cap("sc");
		set_str_cap("cd");
		ft_putstr_cursor_wrap(var);
		update_trackers(var, -(LN_POS - initial_pos));
		set_str_cap("rc");
	}
	return (2);
}

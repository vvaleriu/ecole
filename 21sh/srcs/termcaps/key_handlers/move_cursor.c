/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/15 12:46:27 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Delace le curseur sur la prochaine/precedente case. Calcule le retour a la
** ligne si necessaire
**
** - Si on n'est pas au bout de la string
**	- Si la position actuelle est sur la derniere case, alors on passe le curseur
**	la ligne suivante
** 	- Si non on deplace simplement le curseur vers la gauche
*/
int		move_to_next_char1(t_var *var)
{
	int		i;
	if (var->line.pos < (int)ft_strlen(var->line.s))
	{
		if (!((CUR_POS_X + 1) % var->conf->w.ws_col))
		{
			i = var->conf->w.ws_col;
			set_str_cap("do");
			while (--i > 0)
				set_str_cap("le");
			CUR_POS_X = 0;
			CUR_POS_Y++;
		}
		else
		{
			set_str_cap("nd");
			CUR_POS_X++;
		}
		var->line.pos++;
	}
	return (2);
}

int		move_to_next_char(t_var *var)
{
	if (var->line.pos < (int)ft_strlen(var->line.s))
	{
		if (!((CUR_POS_X + 1) % var->conf->w.ws_col))
		{
			CUR_POS_X = 0;
			CUR_POS_Y++;
		}
		else
			CUR_POS_X++;
		set_str_cap("nd");
			
		var->line.pos++;
	}
	return (2);
}

/*
** On deplace le curseur et on met a jour la position
** - Si on n'est pas au debut de la string
**	- Si la position actuelle est sur la premiere case, alors on passe le curseur
**		sur la ligne precedente
** 	- Si non on deplace simplement le curseur vers la gauche
*/
int		move_to_previous_char1(t_var *var)
{
	int		i;

	if (var->line.pos > 0)
	{
		if (!(CUR_POS_X))
		{
			set_str_cap("up");
			i = -1;
			while (++i < var->conf->w.ws_col)
				set_str_cap("nd");
			CUR_POS_X = var->conf->w.ws_col - 1;
			CUR_POS_Y--;
		}
		else
		{
			set_str_cap("le");
			CUR_POS_X--;
		}
		var->line.pos--;
	}
	return (2);
}

int		move_to_previous_char(t_var *var)
{
	if (var->line.pos > 0)
	{
		if (!(CUR_POS_X))
		{
			CUR_POS_X = var->conf->w.ws_col - 1;
			CUR_POS_Y--;
		}
		else
			CUR_POS_X--;
		set_str_cap("le");
		var->line.pos--;
	}
	return (2);
}

int		move_to_next_line(t_var *var)
{
	t_tconf		*conf;

	
	conf = var->conf;
	(void)conf;
	set_str_cap("do");
	return (2);
}

/*
** Fonction executee lors d'un appui sur home
*/
int		move_to_origin(t_var *var)
{
	set_str_cap("rc");
	var->line.pos = 0;
	CUR_POS_X = PROMPT_LEN;
	CUR_POS_Y = 0;
	return (2);
}

/*
** Fonction executee lors d'un appui sur end
*/
int		move_to_end(t_var *var)
{
	while (var->line.pos < (int)ft_strlen(var->line.s))
		move_to_next_char(var);
	return (2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:51:42 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 10:14:04 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

static void	print_history_line(t_var *var)
{
	update_line_struct(var);
	move_to_origin(var);
	set_str_cap("cd");
	ft_putstr_cursor(var->line.s);
}

/*
** Si on appuie sur les fleches de l'historique sans avoir valide la commande.
** Il faut sauvegarder la commande actuelle de maniere temporaire
*/
void		save_current_input(t_var *var)
{
	if (var->hist.tmp != NULL)
		free(var->hist.tmp);
	var->hist.tmp = ft_strdup(var->line.s);
}

/*
** Lorsqu'on valide une commande. On enregistre la commande passee dans l'
** historique. On efface aussi la sauvegarde temporaire de la commande non finie
** si celle ci avait ete faite. En parallele on verifie que la taille de la
** ne depasse pas un certain point, sans quoi on efface l'element le plus ancien
* avant de rajouter le nouvel element.
*/
int			add_to_history(t_var *var)
{
	t_dlist	*elem;
	char 	*tmp;

	if ((int)ft_dlstlen(var->hist.start) == HIST_LEN)
		ft_dlstdelone(&(var->hist.start), var->hist.start->prev, del_hist_el);
	tmp = ft_strdup(var->line.s);
	elem = ft_dlstnew((void *)tmp, sizeof(char *));
	ft_dlstadd(&(var->hist.start), elem);
	ft_strdel(&(var->hist.tmp));
	return (2);
}

/*
** Remonte dans l'historique. Correspond a la touche UP
** Retourne :
** - 2 si on a affiche une nouvelle entree de l'historique
** - 1 si on a atteint la derniere entree
** - -1 Si l'historique est vide
** si l'historique actuel n'est pas nul. Alors si le suivant n'est pas le debut,
** c'est a dire qu'on a fait le tour, alors on renvoit la chaine
*/
int			history_next(t_var *var)
{
	if (var->hist.cur != NULL)
	{
		if (var->hist.cur->next != var->hist.start)
		{
			var->hist.cur = var->hist.cur->next;
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup((char *)((var->hist.cur)->content));
			print_history_line(var);
			return (2);
		}
		return (1);
	}
	if (!(var->hist.cur))
	{
		if (var->hist.start != NULL)
		{
			save_current_input(var);
			var->hist.cur = var->hist.start;
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup((char *)((var->hist.cur)->content));
			print_history_line(var);
			return (2);
		}
		return (-1);
	}
	return (-1);
}

/*
** Redescend dans l'historique. Correspond a la touche DOWN
** Retourne :
** - Si l'entree actuelle est differente de la premiere
**	- on va a la precedente, on efface la ligne actuelle, on la remplace par
**	  l'entree actuelle et on affche l'historique
** - Si la prochaine entree est celle du depart
**	- on efface la ligne actuelle, on la remplace par la ligne temp
**
*/
int 		history_prev(t_var *var)
{
	if (var->hist.cur != NULL)
	{
		if (var->hist.cur != var->hist.start)
		{
			var->hist.cur = var->hist.cur->prev;
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup((char *)((var->hist.cur)->content));
			print_history_line(var);
			return (2);
		}
		else
		{
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup(var->hist.tmp);
			ft_strdel(&(var->hist.tmp));
			var->hist.cur = NULL;
			print_history_line(var);
			return (1);
		}
	}
	return (-1);
}
/*int 		history_prev(t_var *var)
{
	if (var->hist.cur != NULL)
	{
		if (var->hist.cur->prev != var->hist.start)
		{
			var->hist.cur = var->hist.cur->prev;
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup((char *)((var->hist.cur)->content));
			print_history_line(var);
			return (2);
		}
		else
		{
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup(var->hist.tmp);
			ft_strdel(&(var->hist.tmp));
			var->hist.cur = NULL;
			print_history_line(var);
			return (1);
		}
	}
	return (-1);
}*/
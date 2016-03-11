/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:51:42 by vincent           #+#    #+#             */
/*   Updated: 2016/03/11 23:36:31 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

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
** si celle ci avait ete faite.
*/
int			add_to_history(t_var *var)
{
	t_dlist	*elem;

	elem = ft_dlstnew((void *)ft_strdup(var->line.s), sizeof(char *));
	ft_dlstadd(var->hist.start, elem);
	if (var->hist.tmp)
		ft_strdel(&(var->hist.tmp));
	return (2);
}

/*
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
		if (var->hist.cur->next != *(var->hist.start))
		{
			var->hist.cur = var->hist.cur->next;
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup((char *)((var->hist.cur)->content));
			return (2);
		}
		return (1);
	}
	if (!(var->hist.cur))
	{
		if (var->hist.start != NULL)
		{
			var->hist.cur = *(var->hist.start);
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup((char *)((var->hist.cur)->content));
			return (2);
		}
		return (-1);
	}
	return (-1);
}

/*
** Retourne :
** - -1 si on n'a pas encore demarre dans l'historique
*/
int 		history_prev(t_var *var)
{
	if (var->hist.cur != NULL)
	{
		if (var->hist.cur->prev != *(var->hist.start))
		{
			var->hist.cur = var->hist.cur->prev;
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup((char *)((var->hist.cur)->content));
			return (2);
		}
		else
		{
			ft_strdel(&(var->line.s));
			var->line.s = ft_strdup(var->hist.tmp);
			ft_strdel(&(var->hist.tmp));
			var->hist.cur = NULL;
			return (1);
		}
	}
	return (-1);
}
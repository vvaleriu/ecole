/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:27:20 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/18 10:01:35 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <42sh.h>

/*
** list : liste de token non organisee
** tmp : pointeur vers l'element actuel de cette liste de tokens
** right :
** tk : token de l'element actuel de la liste
** -----------------------------------------------------------------------------
** - Si la longueur de la liste est de 1, alors on n'a pas a ordonner cette
**	 liste et on renvoie directement le seul token de cette liste. On efface
**	 donc l'element de la liste et on retourne le token qui y etait associe
** - Sinon :
**	- On separe la liste depuis le debut jusqu'a l'element actuel (exclusif)
**	  On a donc deux liste : debut -> (elem - 1) et elem -> fin
**	- On relance une fonction de parseur sur la partie gauche
**	- On relance une fonction de parseur sur la partie droite
*/

static t_token		*return_token(t_list *list, t_list **tmp, t_list *right,\
									t_token *tk)
{
	if (ft_lstlen(list) == 1)
	{
		if (*tmp)
		{
			free(*tmp);
			*tmp = NULL;
		}
		return (tk);
	}
	ft_lstsplit(list, *tmp);
	right = ft_lstsplit(*tmp, (*tmp)->next);
	tk->left = (list != *tmp ? parser(list) : NULL);
	tk->right = parser(right);
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (tk);
}

/*
** right :
** tmp : pointe sur la liste de token non organise
** token : token de l'element actuel de la liste
** pty : operateur de priorite
** -----------------------------------------------------------------------------
** Recoit une liste de token non organiser par ordre.
** 	pour chaque element de cette liste, on repere de quoi il s'agit
**	(operateur de priorite, etc), puis on effectue le traitement necessaire
**	On traite bien evidemment les priorites de maniere decroissante, 0 etant la
**	priorite la plus importante.
** -----------------------------------------------------------------------------
** - Si la liste existe de token existe
**	- Tant que la priorite actuelle est inferieure au nombre total de priorites
**	  - Tant que tmp existe (mis au debut de la liste la premiere fois)
**		- Si la prio du token correspond a la prio que l'on traite, alors
**		  on rentre dans return_token.
**		- On traite l'element suivant de la liste
**	  - On remet tmp au debut de la liste et on passe a la priorite suivante
*/

t_token				*parser(t_list *list)
{
	t_list	*right;
	t_list	*tmp;
	t_token	*tk;
	int		pty;

	right = NULL;
	tmp = list;
	pty = 0;
	if (list)
		while (pty < PTY_NB)
		{
			while (tmp)
			{
				tk = (t_token *)tmp->content;
				if (tk->pty == pty)
					return (return_token(list, &tmp, right, tk));
				tmp = tmp->next;
			}
			tmp = list;
			pty++;
		}
	return (NULL);
}

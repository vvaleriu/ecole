/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:09:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:00:10 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_42sh.h>

/*
** Permet de creer un token lorsqu'on a une aggregation de FD
*/

static void		create_fd_aggregation(t_list **ret, t_list **list)
{
	t_list		*tmp;
	t_token		*tk;

	tk = (t_token *)ft_memalloc(sizeof(t_token));
	tk->no = OPS_ROUT;
	tk->pty = PTY_ROUT;
	tk->exe = ft_strsplit((char *)(*list)->content, '>');
	free((char *)(*list)->content);
	tk->left = NULL;
	tk->right = NULL;
	tmp = ft_lstnew((void *)tk, sizeof(t_token));
	ft_lstadd_last(ret, tmp);
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
	tmp = NULL;
}

/*
** Permet de creer un token de commande classique a executer
*/

static void		create_command(t_list **ret, t_list **list)
{
	t_list		*tmp;
	t_token		*tk;

	tk = (t_token *)ft_memalloc(sizeof(t_token));
	tk->no = OPS_EXEC;
	tk->pty = PTY_EXEC;
	tk->exe = create_exe(list);
	tk->left = NULL;
	tk->right = NULL;
	tmp = ft_lstnew((void *)tk, sizeof(t_token));
	ft_lstadd_last(ret, tmp);
}

/*
** Permet de creer un token d'operation.
** On recupere ses caracteristiques puis on l'insere dans la liste
*/

static void		create_ops(t_list **ret, t_list **list, char *ops)
{
	t_list		*tmp;
	t_token		*tk;

	tk = (t_token *)ft_memalloc(sizeof(t_token));
	tk->no = get_op_no(ops);
	tk->pty = get_op_pty(tk->no);
	free((char *)(*list)->content);
	tk->exe = NULL;
	tk->left = NULL;
	tk->right = NULL;
	tmp = ft_lstnew((void *)tk, sizeof(t_token));
	ft_lstadd_last(ret, tmp);
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
	tmp = NULL;
}

/*
** list : pointeur qui parcourt la liste de string creee par le lexer
** ret : liste de tokens a retourner
** tmp : p
** Creer des tokens d'operation. Il contiennent :
** - un numero
** - une priorite
** - un tableau de strings (en fonction du type d'operation)
** - des pointeurs vers les tokens suivants
** -----------------------------------------------------------------------------
** Si le premier caractere du morceau de la commande n'est pas une operande,
**	- On cree un token et on l'ajoute a la fin de la liste, on creant l'exe
** Sinon
**	- On lance creer l'operation
*/

t_list			*create_tokens(t_list *alst)
{
	t_list	*list;
	t_list	*ret;

	ret = NULL;
	list = alst;
	while (list)
	{
		if (is_fd_aggregation((char *)list->content))
			create_fd_aggregation(&ret, &list);
		else if (!is_operator(*((char *)list->content)))
			create_command(&ret, &list);
		else if (list && is_operator(*((char *)list->content)))
			create_ops(&ret, &list, (char *)list->content);
	}
	return (ret);
}

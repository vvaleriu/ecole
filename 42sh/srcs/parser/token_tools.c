/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:52:22 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 11:54:30 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

/*
** Permet de recuperer le numero de l'operation a effectuer
*/

int			get_op_no(char *s)
{
	if (!ft_strncmp(s, ";", 1))
		return (OPS_SEMIC);
	else if (!ft_strncmp(s, "&&", 2))
		return (OPS_AND);
	else if (!ft_strncmp(s, "||", 2))
		return (OPS_OR);
	else if (!ft_strncmp(s, "|", 1))
		return (OPS_PIPE);
	else if (!ft_strncmp(s, "<<", 2))
		return (OPS_DRIN);
	else if (!ft_strncmp(s, ">>", 2))
		return (OPS_DROUT);
	else if (!ft_strncmp(s, "<", 1))
		return (OPS_RIN);
	else if (!ft_strncmp(s, ">", 1))
		return (OPS_ROUT);
	else
		return (10);
}

/*
** Permet de recuperer la priorite de l'operation a effectuer en fonction de
** son numero
*/

int			get_op_pty(int no)
{
	if (no == OPS_SEMIC || no == OPS_AND || no == OPS_OR)
		return (0);
	else if (no == OPS_PIPE)
		return (1);
	else if (no == OPS_EXEC)
		return (3);
	else
		return (2);
}

char		*del_quotes(void **str)
{
	char	*ret;
	char	*s;

	s = *str;
	if (*s == '`')
		return (s);
	if (s)
	{
		ret = (ft_strndup(s + 1, ft_strlen(s + 1) - 1));
		free(*str);
		return (ret);
	}
	return (NULL);
}

/*
** Permet de creer le tableau de chaine de caracteres que lorsqu'il s'agit d'
** executer une commande (nom de l'executable plus les parametres).
** -----------------------------------------------------------------------------
** list : pointeur vers la liste de strings creee par le lexer
** tmp : pointeur pour parcourir cette liste
** i : nombre d'elements de cette liste n'etant ni des operateur ni des
**	redirections
** Pour chaque element trouve, on assigne la chaine de caracteres deja mallocee
** aux tableau exe qui represente l'executable et ses arguments.
*/

char		**create_exe(t_list **list)
{
	int		t[2];
	t_list	*tmp;
	char	**exe;

	I = 0;
	J = 0;
	tmp = *list;
	while (tmp && !is_operator(*((char *)tmp->content)) && \
		!is_fd_aggregation((char *)tmp->content))
	{
		tmp = tmp->next;
		I++;
	}
	exe = (char **)ft_memalloc(sizeof(char *) * (I + 1));
	while (J < I)
	{
		exe[J] = (!is_quote(*((char *)(*list)->content)) ? \
			(char *)(*list)->content : del_quotes(&(*list)->content));
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		J++;
	}
	exe[J] = 0;
	return (exe);
}

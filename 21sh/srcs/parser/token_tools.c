/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:52:22 by vincent           #+#    #+#             */
/*   Updated: 2016/03/31 20:00:10 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

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
/*
**
*/
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
**
** list : pointeur vers la liste de strings creee par le lexer
** tmp : pointeur pour parcourir cette liste
** i : nombre d'elements de cette liste n'etant ni des operateur ni des
**	redirections
** Pour chaque element trouve, on assigne la chaine de caracteres deja mallocee
** aux tableau exe qui represente l'executable et ses arguments.
*/
char		**create_exe(t_list **list)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	**exe;

	i = 0;
	j = 0;
	tmp = *list;
	while (tmp && !is_operator(*((char *)tmp->content)) && \
		!is_fd_aggregation((char *)tmp->content))
	{
		tmp = tmp->next;
		i++;
	}
	exe = (char **)ft_memalloc(sizeof(char *) * i + 1);
	while (j < i)
	{
		exe[j] = (!is_quote(*((char *)(*list)->content)) ? \
			(char *)(*list)->content : del_quotes(&(*list)->content));
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		j++;
	}
	exe[j] = 0;
	return (exe);
}

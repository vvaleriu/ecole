/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:09:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 12:26:45 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_minishell2.h>

int				get_op_no(char *s)
{
	if (!ft_strncmp(s, ";", 1))
		return (OPS_SEMIC);
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

int				get_op_pty(int no)
{
	if (no == 0)
		return (0);
	else if (no == 1)
		return (1);
	else if (no == 6)
		return (3);
	else
		return (2);
}

static char		**create_exe(t_list **list)
{
	int		i;
	int		j;
	t_list	*tmp;
	char	**exe;

	i = 0;
	j = 0;
	tmp = *list;
	while (tmp && !is_operator(*((char *)tmp->content)))
	{
		tmp = tmp->next;
		i++;
	}
	exe = (char **)ft_memalloc(sizeof(char *) * i + 1);
	while (j < i)
	{
		exe[j] = (char *)(*list)->content;
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
		tmp = NULL;
		j++;
	}
	exe[j] = 0;
	return (exe);
}

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

t_list			*create_tokens(t_list *alst)
{
	t_list	*list;
	t_list	*ret;
	t_list	*tmp;
	t_token	*tk;

	ret = NULL;
	list = alst;
	while (list)
	{
		if (!is_operator(*((char *)list->content)))
		{
			tk = (t_token *)ft_memalloc(sizeof(t_token));
			tk->no = OPS_EXEC;
			tk->pty = PTY_EXEC;
			tk->exe = create_exe(&list);
			tk->left = NULL;
			tk->right = NULL;
			tmp = ft_lstnew((void *)tk, sizeof(t_token));
			ft_lstadd_last(&ret, tmp);
		}
		else if (list && is_operator(*((char *)list->content)))
			create_ops(&ret, &list, (char *)list->content);
	}
	return (ret);
}

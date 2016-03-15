/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:56:27 by vincent           #+#    #+#             */
/*   Updated: 2016/03/15 18:19:24 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int			copy_from_start(t_var *var)
{
	if (ft_strlen(LN_S))
	{
		ft_strdel(&(LN_CPY));
		LN_CPY = ft_strndup(LN_S, LN_POS);
	}
	return (2);
}

int			copy_from_end(t_var *var)
{
	if (ft_strlen(LN_S + LN_POS))
	{
		ft_strdel(&(LN_CPY));
		LN_CPY = ft_strdup(LN_S + LN_POS);
	}
	return (2);
}

/*
** j
*/
int			cut_from_start(t_var *var)
{
	int		i;

	i = ft_strlen(LN_S + LN_POS);
	if (ft_strlen(LN_S))
	{
		copy_from_start(var);
		ft_strncpy(LN_S, LN_S + LN_POS, i);
		while (LN_S[i] != '\0')
		{
			LN_S[i] = '\0';
			i++;
		}
		set_str_cap("rc");
		set_str_cap("cd");
		ft_putstr_cursor(LN_S);
		move_to_origin(var);
	}
	return (2);
}

int			cut_from_end(t_var *var)
{
	int		i;

	i = LN_POS;
	if (ft_strlen(LN_S + LN_POS))
	{
		copy_from_end(var);
		set_str_cap("cd");
		while (LN_S[i] != '\0')
		{
			LN_S[i] = '\0';
			i++;
		}
	}
	return (2);
}

/*
** GERER le stoc
**
*/
int			paste(t_var *var)
{
	char	*tmp;

	if (LN_CPY != NULL)
	{
		set_str_cap("sc");
		tmp = ft_strnew(ft_strlen(LN_S) + ft_strlen(LN_CPY));
		ft_strncpy(tmp, LN_S, LN_POS);
		ft_strcpy(tmp + LN_POS, LN_CPY);
		ft_strcpy(tmp + LN_POS + ft_strlen(LN_CPY), LN_S + LN_POS);
		ft_putstr_cursor(LN_S);
		set_str_cap("rc");
		update_line_struct(var);
	}
	return (2);
}
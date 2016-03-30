/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:33:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/30 19:54:00 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void	lex_space(t_var *var, char **buf, t_list **alst)
{
	(void *)var;
	while (is_space(**buf) == 1)
		(*buf)++;
	*alst = NULL;
}

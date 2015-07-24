/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:33:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2014/04/25 21:42:13 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void	lex_space(char **buf, t_list **alst)
{
	while (is_space(**buf) == 1)
		(*buf)++;
	*alst = NULL;
}

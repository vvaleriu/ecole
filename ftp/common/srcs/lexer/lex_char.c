/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:43:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/26 19:55:36 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp_server.h>

void		lex_char(char **buf, t_list **alst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (is_text((*buf)[i]) && (*buf)[i])
		i++;
	tmp = ft_lstnew((void *)ft_strndup(*buf, i), sizeof(char *));
	*buf += i;
	ft_lstadd_last(alst, tmp);
}

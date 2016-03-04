/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str_cap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:23:21 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 11:46:45 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** List of capabilities string is sent with a ":" separator
** The function then split the cap and set them one after the other.
*/

void			set_str_cap(char *cap_str)
{
	char	**cap;
	char	**tmp;
	char    *res;

	cap = ft_strsplit(cap_str, ':');
	tmp = cap;
	while (*cap != 0)
	{
		res = err_void(NULL, tgetstr(*cap, NULL), ERR_TERM_CAP_UNDEF, 0);
		if (res)
			tputs(res, 1, putchar_int);
		cap++;
	}
	ft_strarray_del(&tmp);
}
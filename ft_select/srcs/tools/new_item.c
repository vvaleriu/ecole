/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:35:19 by vincent           #+#    #+#             */
/*   Updated: 2015/08/01 01:50:47 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_item		*new_item(char *str)
{
	t_item	*ret;

	ret = (t_item*)ft_memalloc(sizeof(t_item));
	if (!ret)
		return (NULL);
	ret->s = (str != NULL ? str : NULL);
	ret->sel = 0;
	ret->x = 0;
	ret->y = 0;
	ret->len = ft_strlen(str);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 01:27:32 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 13:21:08 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_tconf 		*get_instance()
{
	static t_tconf *conf = NULL;
 
	if (conf == NULL)
	{
		conf = (t_tconf *)ft_memalloc(sizeof(*conf));
		return (conf);
	}
	return (conf);
}
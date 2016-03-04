/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 01:27:32 by vincent           #+#    #+#             */
/*   Updated: 2016/03/03 07:28:44 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Return a singleton of conf structure
*/
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:12:38 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/06/27 13:38:24 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp_client.h>

t_cl_prop	*get_instance(void)
{
	static t_cl_prop *instance = NULL;

	if (instance == NULL)
		return ((instance = ft_memalloc(sizeof(*instance))));
	return instance;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 11:12:38 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/06/27 11:26:10 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp_server.h>

t_sv_prop	*get_instance(void)
{
	static t_sv_prop *instance = NULL;

	if (instance == NULL)
		return ((instance = ft_memalloc(sizeof(*instance))));
	return instance;
}
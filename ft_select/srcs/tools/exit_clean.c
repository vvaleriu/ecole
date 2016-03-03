/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 01:27:32 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 17:15:06 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void			exit_clean(t_tconf *conf)
{
	ft_dlstdel(&(conf->list), del_list_elem);
	free(conf);
}
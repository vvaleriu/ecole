/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 07:26:26 by vincent           #+#    #+#             */
/*   Updated: 2016/07/12 15:38:48 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_fillit_inst	*get_instance(void)
{
	static t_fillit_inst *instance = NULL;

	if (!instance)
		return ((instance = (t_fillit_inst*)ft_memalloc(sizeof(*instance))));
	return (instance);
}
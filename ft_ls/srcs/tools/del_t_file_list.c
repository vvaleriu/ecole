/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_file_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 00:29:54 by vincent           #+#    #+#             */
/*   Updated: 2015/08/08 19:16:37 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdlib.h>

void 	del_t_file_list(void *content, size_t size)
{
	//t_file	*file;

	(void)&size;
	/*file = (t_file *)content;
	faire un free sur chaque element a fee contenu dans la structure*/
	free(content);
}
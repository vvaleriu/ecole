/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_small_size_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2016/03/03 13:08:21 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Print an error message when screen to small to print full list
*/

void		print_small_size_error()
{
	set_str_cap("cl");
	move_to(0, 0);
	ft_printf("Agrandir la fenêtre.");
}
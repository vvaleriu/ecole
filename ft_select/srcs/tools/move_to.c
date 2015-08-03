/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 00:40:46 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void 		move_to(int x, int y)
{
	char *res;
 
	res = tgetstr("cm", NULL);
	if (!res)
		ft_printf("error cursor motion\n");
	tputs(tgoto(res, x, y), 1, putchar_int);
}
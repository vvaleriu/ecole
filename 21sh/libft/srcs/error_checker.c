/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 18:34:03 by vincent           #+#    #+#             */
/*   Updated: 2016/04/04 19:27:34 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errno.h>
#include <stdlib.h>

/*
**	Compares the results (res) to an error result (err) return by a function
**	if quit is != 0 then the program exits.
*/

int			err_int(int err, int res, char *str, int quit)
{
	if (err == res)
	{
		ft_printf("%s %s\n", (quit ? "Exit: " : NULL ), str);
		if (quit)
			exit(2);
	}
	return (res);
}

void		*err_void(void *err, void *res, char *str, int quit)
{
	if (res == err)
	{
		ft_printf("%s %s\n", (quit ? "Exit:" : NULL ), str);
		if (quit)
			exit(2);
	}
	return (res);
}
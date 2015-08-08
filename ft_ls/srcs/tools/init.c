/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 12:37:43 by vincent           #+#    #+#             */
/*   Updated: 2015/08/08 01:37:03 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** set_var: initialise array values
** set_options arguments
*/

static void set_var(t_lsprop *prop)
{
	int		i;

	i = 0;
	while (i < OPTIONS_NB)
		prop->opt[i++] = 0;
	reset_print_prop(prop->pp);
}

int			init(t_lsprop *prop, int ac, char **av)
{
	set_var(prop);
	prop->il = NULL;
	prop->first_time = 1;
	return (set_options(prop, ac, av));
}
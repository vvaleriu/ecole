/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 17:43:19 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/09 00:19:04 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** verifie si l'argument est une option.
** si oui, alors si option courte '-' ou longue '--', appelle la focntion 
** correspondante
** si une des options rentrees n'existe pas, alors renvoie -1 erreur option
** illegale
*/

static int		check_short(t_lsprop *prop, char *ar)
{
	while (*++ar)
	{
		OPT_L = (*ar == 'l' ? 1 : OPT_L);
		OPT_A = (*ar == 'a' ? 1 : OPT_A);
		OPT_RC = (*ar == 'R' ? 1 : OPT_RC);
		OPT_T = (*ar == 't' ? 1 : OPT_T);
		OPT_R = (*ar == 'r' ? 1 : OPT_R);
		if (*ar != 'l' && *ar != 'a' && *ar != 'R' && *ar != 't' && *ar != 'r')
			return (-1);
	}
	return (1);
}

static int 		check_long(t_lsprop *prop, char *arg)
{
	if (!ft_strcmp(arg, "--all"))
	{
		OPT_A = 1;
		return (1);
	}
	else if (!ft_strcmp(arg, "--reverse"))
	{
		OPT_R = 1;
		return (1);
	}
	else if (!ft_strcmp(arg, "--recursive"))
	{
		OPT_RC = 1;
		return (1);
	}
	else
		return (-1);
}

int		set_options(t_lsprop *prop, int ac, char **av)
{
	static int	t[2] = {1, 0};

	if (ac == 1)
		return (0);
	while (av[I])
	{
		if (av[I][0] == '-' && av[I][1] == '-')
			J = check_long(prop, av[I]);
		else if (av[I][0] == '-')
			J = check_short(prop, av[I]);
		if (J == -1)
			return (-1);
		I++;
	}
	return (1);
}

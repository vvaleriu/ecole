/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 12:38:57 by vincent           #+#    #+#             */
/*   Updated: 2016/07/28 01:37:05 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		main(int ac, char **av)
{
	t_lemin_var		*var;

	if (!(var = init()))
	{
		ft_printf("ERROR");
		return (0);
	}
	if (!read_entry(var))
		return (clean(&var));
	var->rooms = var->lstart;
	if (algo(var) == -1)
		return (clean(&var));
	if (ac == 2 && !ft_strcmp(av[1], "-d"))
	{
		ft_dlstiter(var->lstart, print_room_dlist);
		print_all_paths(var);
		print_ants(var);
	}
	print_mouv(var);
	clean(&var);
	return (0);
}
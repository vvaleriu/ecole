/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 12:38:57 by vincent           #+#    #+#             */
/*   Updated: 2016/07/26 15:46:25 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		main()
{
	t_lemin_var		*var;
	//t_dlist			*path;

	//path = NULL;
	if (!(var = init()))
	{
		ft_printf("ERROR");
		return (0);
	}
	read_entry(var);
	var->rooms = var->lstart; // On place le debut au maillon de debut

	algo(var);

	print_all_paths(var);
	//print_ants(var);
	print_mouv(var);

	// On reset pour la recherche en profondeur
	/*ft_printf("[Reset des pieces necessaires apres le meilleur chemin :]\n");
	var->start->tag = 0;
	var->end->tag = 0;
	ft_dlstiter(var->rooms, print_room_dlist);*/

	// DEEP SEARCH
	/*ft_printf("[== RESTE DES CHEMIN (BST) ==]\n");
	deep_search(var, var->start, &path);*/

	clean(var);
	if (var)
		free(var);
	return (0);
}
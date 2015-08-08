/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_filenames_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 23:38:29 by vincent           #+#    #+#             */
/*   Updated: 2015/08/09 00:54:41 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** create a list of filenames sent in arguments to run ft_ls on.
** browse the argument and each time the arg is not an option, it adds the arg
** to the chained list
** if no argument if passed, then the return list will only contain "."
*/

t_list		*create_filenames_list(int ac, char **av)
{
	int		i;
	t_list 	*ret;

	ret = NULL;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-')
			ft_lstadd_last(&ret, ft_lstnew(av[i], sizeof(char *)));
		i++;
	}
	return (ret);
}

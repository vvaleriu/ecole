/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:02:36 by vincent           #+#    #+#             */
/*   Updated: 2015/08/11 16:26:19 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>
/*
** receive a list
*/

static void	print_in_list(t_lsprop *prop, t_file *file)
{
	short	*pp;

	pp = prop->pp;
	ft_printf("%c%s%c %*s %*s %*s %*s %*s %s\n", 
		file->type, file->rights, file->xattr, LK_L, file->link_nb,
		GRP_L, file->group, USR_L, file->user, SIZE_L, file->size,
		MOD_L, file->mod, file->name);
}

static void print_classic(t_lsprop *prop, t_file *file)
{
	(void)prop;
	ft_printf("%s\n", file->name);
}

void		print_elem(t_lsprop *prop, t_file *file)
{
	void	(*ptft)(t_lsprop *, t_file *);

	ptft = (OPT_L ? print_in_list : print_classic);
	if (!OPT_A)
	{
		if (file->name[0] != '.')
			ptft(prop, file);
	}
	else
		ptft(prop, file);
}
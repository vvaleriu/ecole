/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 18:02:36 by vincent           #+#    #+#             */
/*   Updated: 2015/08/09 00:50:36 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stdio.h>
/*
** receive a list
*/

/*static void	print_in_list(t_lsprop *prop, t_file *file)
{
	(void)prop;
	ft_printf("%c%s %c %s %s %s %s %s %s\n", file->type, file->rights, file->xattr,
				file->link_nb, file->group, file->user, file->size, file->mod,
				file->name);
}*/

/*static void print_pp(t_lsprop *prop)
{
	short	*pp;

	pp = prop->pp;
	ft_printf("GRP_L: %d, USR_L: %d, SIZE_L: %d, MOD_L: %d\n",
		GRP_L, USR_L, SIZE_L, MOD_L);
}
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
	ptft(prop, file);

}
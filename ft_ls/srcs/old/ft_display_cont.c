/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cont.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:43:26 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 15:43:28 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_dis_param(t_file_prop *file, t_options opt, t_print_prop pt);

void	ft_display_cont(t_list *alst, t_options opt, t_print_prop pt)
{
	if (opt.t)
		ft_sort_date(&alst);
	else if (opt.r)
		ft_sort_alpha_inv(&alst);
	else
		ft_sort(&alst);
	if (opt.l)
	{
		ft_putstr("total ");
		ft_putnbr(pt.blk);
		ft_putchar('\n');
	}
	while (alst)
	{
		ft_dis_param((t_file_prop *)alst->content, opt, pt);
		ft_putchar('\n');
		alst = alst->next;
	}
}

void	ft_dis_param(t_file_prop *file, t_options opt, t_print_prop pt)
{
	if (opt.l)
	{
		ft_putstr(file->filetype);
		ft_putstr(file->rights);
		ft_putstr(file->xattr);
		ft_disp_link_nb(file->link_nb, pt.lk_l);
		ft_disp_user(file->user, pt.usr_l);
		ft_disp_group(file->group, pt.grp_l);
		if (CMP(file->filetype, "c") == 0 || CMP(file->filetype, "b") == 0)
		{
			ft_disp_min(file->min, pt.min_l);
			ft_disp_man(file->man, pt.man_l);
		}
		else
			ft_disp_size(file->size, pt);
		ft_disp_mod(file->mod, pt.mod_l);
	}
	ft_putstr(file->name);
	if (opt.l)
		ft_disp_link_name(file->lk, file->filetype);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 07:41:12 by vincent           #+#    #+#             */
/*   Updated: 2016/07/20 00:25:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		parse_link(t_lemin_var *var, char **split)
{
	int			len;
	t_vertex	*r1;
	t_vertex	*r2;

	len = ft_strarray_len(split);
	if (len != 2)
		return (0);
	if (!(r1 = find_room_by_name(var, split[0])) ||
		!(r2 = find_room_by_name(var, split[1])))
		return (0);
	if (r1 == r2)
		return (0);
	ft_dlstadd_last(&(r1->lks), ft_dlstnew((void *)r2, sizeof(*r2)));
	ft_dlstadd_last(&(r2->lks), ft_dlstnew((void *)r1, sizeof(*r1)));
	r1->lk_nb++;
	r2->lk_nb++;
	return (1);
}
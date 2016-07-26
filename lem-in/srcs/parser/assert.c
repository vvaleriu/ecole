/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 12:49:04 by vincent           #+#    #+#             */
/*   Updated: 2016/07/19 18:46:57 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				is_room_name_correct(char *str)
{
	return (*str != 'L');
}

int				is_digit_only(char *len)
{
	while (*len)
	{
		if (!ft_isdigit(*len))
			return (0);
		len++;
	}
	return (1);
}

int				are_rcoord_correct(char **split, int len)
{
	if (len < 3)
		return (0);
	if (!is_digit_only(split[len - 1]) || !is_digit_only(split[len - 2]))
		return (0);
	return (1);
}
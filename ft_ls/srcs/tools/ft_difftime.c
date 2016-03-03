/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_difftime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 22:44:42 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/05 12:15:51 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

long int		ft_difftime(time_t time1, time_t time2)
{
	return ((long int) (time1 - time2));
}
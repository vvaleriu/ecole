/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:35:01 by vvaleriu          #+#    #+#             */
/*   Updated: 2014/02/11 01:49:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	if (c == ' ' || c == 9)
		return (1);
	return (0);
}
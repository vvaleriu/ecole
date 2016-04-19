/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:43:52 by graybaud          #+#    #+#             */
/*   Updated: 2016/03/28 13:43:54 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
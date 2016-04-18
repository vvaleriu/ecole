/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 12:21:28 by graybaud          #+#    #+#             */
/*   Updated: 2016/03/31 12:21:29 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_read_token(char *token, t_stack *stack)
{
	if (ft_is_number(token))
		return (ft_push_stack(stack, ft_atof(token), 0));
	if (ft_is_operator(token[0]))
		return (ft_postfix(stack, token[0]));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:54:55 by graybaud          #+#    #+#             */
/*   Updated: 2016/03/28 13:54:59 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "main.h"

int	ft_add(t_stack *stack)
{
	double	a;
	double	b;

	a = 0;
	b = 0;
	if (!ft_pop_stack(stack, &b, 0))
		return (0);
	if (!ft_pop_stack(stack, &a, 0))
		return (0);
	a += b;
	if (!(ft_push_stack(stack, a, 0)))
		return (0);
	return (1);
}

int	ft_sub(t_stack *stack)
{
	double	a;
	double	b;

	a = 0;
	b = 0;
	if (!ft_pop_stack(stack, &b, 0))
		return (0);
	if (!ft_pop_stack(stack, &a, 0))
		return (0);
	a -= b;
	if (!(ft_push_stack(stack, a, 0)))
		return (0);
	return (1);
}

int	ft_mult(t_stack *stack)
{
	double	a;
	double	b;

	a = 0;
	b = 0;
	if (!ft_pop_stack(stack, &b, 0))
		return (0);
	if (!ft_pop_stack(stack, &a, 0))
		return (0);
	a *= b;
	if (!(ft_push_stack(stack, a, 0)))
		return (0);
	return (1);
}

int	ft_divi(t_stack *stack)
{
	double	a;
	double	b;

	a = 0;
	b = 0;
	if (!ft_pop_stack(stack, &b, 0))
		return (0);
	if (!ft_pop_stack(stack, &a, 0))
		return (0);
	if (b == 0)
	{
		ft_printf("wrong denominator\n");
		exit(1);
	}
	a /= b;
	if (!(ft_push_stack(stack, a, 0)))
		return (0);
	return (1);
}

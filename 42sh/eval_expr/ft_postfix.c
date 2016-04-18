/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_postfix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 14:06:17 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:45:46 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_postfix(t_stack *stack, char token)
{
	static t_expr	tab[] = {	{'+', ft_add},
								{'-', ft_sub},
								{'*', ft_mult},
								{'/', ft_divi},
								{'\0', 0}};
	int				i;

	i = 0;
	while (tab[i].c != '\0')
	{
		if (tab[i].c == token)
			return (tab[i].ft_operation(stack));
		++i;
	}
	return (0);
}

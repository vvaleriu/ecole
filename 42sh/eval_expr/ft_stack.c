/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:27:36 by graybaud          #+#    #+#             */
/*   Updated: 2016/03/28 13:27:38 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "main.h"

t_stack	*ft_init_stack(void)
{
	t_stack	*t;

	if (!(t = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	t->size = 0;
	t->top = NULL;
	return (t);
}

int		ft_stack_empty(t_stack *stack)
{
	return (stack->size == 0);
}

int		ft_push_stack(t_stack *stack, double nb, char *s)
{
	t_stack_node	*t;

	if (!(t = (t_stack_node *)malloc(sizeof(t_stack_node))))
		return (0);
	t->nb = nb;
	if (s)
		t->str = ft_strdup(s);
	else
		t->str = 0;
	t->next = stack->top;
	stack->top = t;
	stack->size++;
	return (1);
}

int		ft_pop_stack(t_stack *stack, double *nb, char **s)
{
	t_stack_node	*t;

	t = stack->top;
	if (ft_stack_empty(stack))
		return (0);
	if (nb)
		*nb = t->nb;
	if (s)
		*s = ft_strdup(t->str);
	stack->top = t->next;
	stack->size--;
	free(t);
	return (1);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack_node	*t;

	t = stack->top;
	while (t != NULL)
	{
		ft_printf("%f\n", t->nb);
		t = t->next;
	}
}

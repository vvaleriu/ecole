/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shunting_yard.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:40:42 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:48:35 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "main.h"

static int	ft_push_operator(t_env *env)
{
	char	*s;
	double	top;
	double	curr;

	top = 0;
	curr = ft_get_precedence(env->arg[env->i][0]);
	if (ft_stack_empty(env->stack))
		return (ft_push_stack(env->stack, curr, env->arg[env->i]));
	else
	{
		top = env->stack->top->nb;
		while (env->stack->size > 0 && top >= curr)
		{
			ft_pop_stack(env->stack, 0, &s);
			ft_enqueue(env->queue, s);
			if (ft_stack_empty(env->stack))
				break ;
			top = env->stack->top->nb;
		}
		return (ft_push_stack(env->stack, curr, env->arg[env->i]));
	}
	return (0);
}

static int	ft_push_bracket(t_env *env)
{
	char	*s;
	int		test;

	test = 0;
	if (ft_stack_empty(env->stack))
		return (0);
	else
	{
		while (test != '(')
		{
			test = env->stack->top->str[0];
			if (test == '(')
				return (ft_pop_stack(env->stack, 0, 0));
			ft_pop_stack(env->stack, 0, &s);
			ft_enqueue(env->queue, s);
			if (ft_stack_empty(env->stack) && test != '(')
			{
				ft_printf("missing bracket\n");
				exit(1);
			}
		}
	}
	return (0);
}

static void	ft_pop_stack_operator(t_env *env)
{
	char	*s;

	s = env->stack->top->str;
	while (env->stack->size > 0)
	{
		ft_pop_stack(env->stack, 0, &s);
		ft_enqueue(env->queue, s);
	}
}

static int	ft_parse_token(t_env *env)
{
	if (ft_is_number(env->arg[env->i]))
		return (ft_enqueue(env->queue, env->arg[env->i]));
	else if (ft_is_operator(env->arg[env->i][0]))
		return (ft_push_operator(env));
	else if (env->arg[env->i][0] == '(')
		return (ft_push_stack(env->stack, 0, env->arg[env->i]));
	else if (env->arg[env->i][0] == ')')
		return (ft_push_bracket(env));
	else
	{
		ft_printf("unknow operand \n");
		exit(1);
	}
	return (0);
}

void		ft_shunting_yard(t_env *env)
{
	env->i = 0;
	while (env->arg[env->i])
	{
		if (!ft_parse_token(env))
			break ;
		env->i++;
	}
	if (!ft_stack_empty(env->stack))
		ft_pop_stack_operator(env);
	free(env->arg);
}

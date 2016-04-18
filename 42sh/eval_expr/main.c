/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:51:59 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 12:34:17 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "main.h"

static int	ft_inspect_argument(t_env *env, char *arg)
{
	char *inspector;

	inspector = arg;
	if (!inspector || *arg == '\0')
	{
		free(env);
		return (1);
	}
	inspector = ft_strndup((arg + 3), ft_strlen(inspector) - 5);
	env->arg = ft_strsplit(inspector, ' ');
	free(inspector);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	env = ft_init_env();
	if (ac == 2)
	{
		if (ft_inspect_argument(env, av[1]))
			return (1);
		env->arg = ft_strsplit(av[1], ' ');
		ft_shunting_yard(env);
		while (env->queue->size > 0)
		{
			ft_dequeue(env->queue, &(env->token));
			if (!ft_read_token(env->token, env->stack))
				break ;
		}
		ft_check_error(env);
	}
	else
		return (1);
	return (0);
}

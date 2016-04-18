/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:16:21 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:43:53 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "main.h"

void	ft_check_error(t_env *env)
{
	if (env->stack->size > 1 || ft_stack_empty(env->stack))
		ft_printf("invalid expression\n");
	else if (env->stack->size == 1)
		ft_print_stack(env->stack);
	free(env);
}

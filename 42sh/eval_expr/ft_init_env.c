/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 12:41:19 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 12:41:20 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "main.h"

t_env	*ft_init_env(void)
{
	t_env *t;

	if (!(t = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	t->i = 0;
	t->token = ft_memalloc(1);
	t->arg = NULL;
	t->stack = ft_init_stack();
	t->queue = ft_init_queue();
	return (t);
}

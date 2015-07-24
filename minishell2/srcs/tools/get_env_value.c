/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:02:51 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/03 13:14:47 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>
#include <libft.h>

char	*get_env_value(char *var, char **env)
{
	int		i;

	i = ft_find_env(var, env);
	if (i != -1)
		return (env[i] + ft_strlen(var) + 1);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:01:43 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 15:33:04 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int			find_env(char *exe, char **env)
{
    int		i;
    int		j;
    char	*cmp;

    i = 0;
    j = 0;
    while (env[i])
    {
        while (env[i][j] && env[i][j] != '=')
            j++;
        cmp = ft_strndup(env[i], j);
        if (!ft_strcmp(cmp, exe))
        {
            ft_strdel(&cmp);
            return (i);
        }
        ft_strdel(&cmp);
        i++;
        j = 0;
    }
    return (-1);
}
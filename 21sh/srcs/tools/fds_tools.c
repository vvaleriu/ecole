/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 11:56:25 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/27 13:20:17 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Fait une copie du l'entree et la sortie standard dans les deux premiers fds
** libres qu'il trouve et les enregistre dans un tableau
*/
void			save_std_fds(int *fds)
{
	fds[0] = dup(0);
	fds[1] = dup(1);
}

/*
** Restore les copies des fds standards dans les fd origineaux
*/
void			restore_std_fds(int *fds)
{
	dup2(fds[0], 0);
	dup2(fds[1], 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:52:22 by vincent           #+#    #+#             */
/*   Updated: 2016/03/22 21:52:58 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Permet de recuperer le numero de l'operation a effectuer
*/
int				get_op_no(char *s)
{
	if (!ft_strncmp(s, ";", 1))
		return (OPS_SEMIC);
	else if (!ft_strncmp(s, "|", 1))
		return (OPS_PIPE);
	else if (!ft_strncmp(s, "<<", 2))
		return (OPS_DRIN);
	else if (!ft_strncmp(s, ">>", 2))
		return (OPS_DROUT);
	else if (!ft_strncmp(s, "<", 1))
		return (OPS_RIN);
	else if (!ft_strncmp(s, ">", 1))
		return (OPS_ROUT);
	else
		return (10);
}

/*
** Permet de recuperer la priorite de l'operation a effectuer en fonction de
** son numero
*/
int				get_op_pty(int no)
{
	if (no == 0)
		return (0);
	else if (no == 1)
		return (1);
	else if (no == 6)
		return (3);
	else
		return (2);
}

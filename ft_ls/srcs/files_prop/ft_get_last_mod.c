/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 19:38:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 19:12:37 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Prends en parametre une structure timespec (voir _struct.h pour plus de 
** details). Passe le parametre tv_sec de la struture timespec a la fonction
** ctime pour obtenir la date de derniere modification du fichier
*/

/*char	*ft_get_last_mod(struct timespec st_timesp)
{
	long int	a;
	char		*s1;
	char		*s2;

	a = ft_difftime(st_timesp.tv_sec, time(0));
	if (a > -15778463 && a < 15778463)
		return (ft_strsub(ctime(&(st_timesp.tv_sec)), 4, 12));
	else
	{
		s1 = ft_strsub(ctime(&(st_timesp.tv_sec)), 4, 7);
		s2 = ft_strsub(ctime(&(st_timesp.tv_sec)), 19, 5);
		s1 = ft_strcat(s1, s2);
		return (s1);
	}
}*/

char	*ft_get_last_mod(t_timespec st_timesp)
{
	long int	a;
	char		*s1;
	char		*s2;

	a = ft_difftime(st_timesp, time(0));
	if (a > -15778463 && a < 15778463)
		return (ft_strsub(ctime(&st_timesp), 4, 12));
	else
	{
		s1 = ft_strsub(ctime(&st_timesp), 4, 7);
		s2 = ft_strsub(ctime(&st_timesp), 19, 5);
		s1 = ft_strcat(s1, s2);
		return (s1);
	}
}

/*
char	*ft_get_last_mod(time_t st_timesp)
{
	(void)st_timesp;
	char *tmp = ft_strnew(4);
	ft_strcpy(tmp, "loli");
	return (tmp);
}*/

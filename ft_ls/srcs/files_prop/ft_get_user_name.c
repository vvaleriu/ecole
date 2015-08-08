/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 17:26:06 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/09 00:54:11 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
**
*/

char	*ft_get_user_name(uid_t st_uid)
{
	t_passwd	*pwd;

	pwd = getpwuid(st_uid);
	if (!pwd)
	{
		//perror(strerror(errno));
		return (NULL);
	}
	return (pwd->pw_name);
}

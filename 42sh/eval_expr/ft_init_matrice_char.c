/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_matrice_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:40:17 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:43:36 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_init_matrice_char(int len)
{
	char	**t;

	if (!(t = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	t[len] = 0;
	return (t);
}

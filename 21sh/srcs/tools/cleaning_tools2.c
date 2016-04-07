/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 08:51:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 08:15:14 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>
#include <libft.h>
#include <stdlib.h>

void		clean_tree(t_token *root)
{
	int i;

	if (root)
	{
		if (root->left)
			clean_tree(root->left);
		if (root->right)
			clean_tree(root->right);
		if (root->exe)
		{
			if (root->no == OPS_ROUT)
				ft_strdel(root->exe);
			else
			{
				i = -1;
				while ((++i != 0 || i == 0) && root->exe[i] != 0)
					ft_strdel(&(root->exe[i]));
				free(root->exe);
				root->exe = NULL;
			}
		}
		free(root);
		root = NULL;
	}
}

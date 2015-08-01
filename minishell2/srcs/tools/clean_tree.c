/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 18:07:40 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/26 11:54:41 by vvaleriu         ###   ########.fr       */
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
			i = 0;
			while (root->exe[i] != 0)
			{
				ft_strdel(&(root->exe[i]));
				i++;
			}
			free(root->exe);
			root->exe = NULL;
		}
		free(root);
		root = NULL;
	}
}

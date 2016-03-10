/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:13:09 by vincent           #+#    #+#             */
/*   Updated: 2016/03/10 23:04:35 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Augmente la capacite de la ligne de commande actuelle. La nouvelle capacite
** est egale a l'ancienne plus la longeur par defaut d'une ligne de commande
** (CMD_LENGTH)
*/
static void	extend_line_capacity(t_var *var)
{
	char	*newline;

	newline = ft_strnew(var->line->max + CMD_LENGTH);
	var->line.max += CMD_LENGTH;
	ft_strcpy(newline, var->line.s);
	free(var->line.s);
	var->line.s = newline;
}

static void insert_character(t_var *var)
{
	size_t	len;

	len = ft_strlen(var->line.s);
	while (len > var->line.pos)
	{
		var->line.s[len] = var->line.s[len - 1];
		len--;
	}
	var->line.s[var->line.pos] = var->key_buf[0];
	(var->line.pos)++;
}


static void delete_character(t_var *var)
{
	size_t	len;
	int 	i;

	len = ft_strlen(var->line.s);
	(var->line.pos)--;
	var->line.s[var->line.pos] = '\0';
	i = var->line.pos;
	while (i < len)
	{
		var->line.s[i] = var->line.s[i + 1];
		i++;
	}
}

void		build_line(t_var *var)
{
	if (ft_strlen(var->line) == var->line->max)
		extend_line_capacity(var);
	var->line.s[var->line->pos] = var->key_buf[0];
	(var->line.pos)++;
}
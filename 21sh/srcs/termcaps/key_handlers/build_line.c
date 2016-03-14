/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 22:13:09 by vincent           #+#    #+#             */
/*   Updated: 2016/03/14 14:26:49 by vvaleriu         ###   ########.fr       */
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
	char	*new_line_buffer;

	new_line_buffer = ft_strnew(var->line.max + CMD_LENGTH);
	var->line.max += CMD_LENGTH;
	ft_strcpy(new_line_buffer, var->line.s);
	free(var->line.s);
	var->line.s = new_line_buffer;
}

/*
** Si la chaine est trop courte on l'agrandit. Tant qu'on n'a pas atteint la
** position du curseur, on copie chaque caractere dans la case suivane. Enfin
** on insere le caractere
** Pour finir on affiche la ligne
*/
int			insert_char(t_var *var)
{
	size_t	len;

	if (ft_strlen(var->line.s) == var->line.max)
		extend_line_capacity(var);
	len = ft_strlen(var->line.s);
	while ((int)len > var->line.pos)
	{
		var->line.s[len] = var->line.s[len - 1];
		len--;
	}
	var->line.s[var->line.pos] = var->key_buf[0];
	//ft_putchar_cursor(var->line.s[var->line.pos]);
	ft_putstr_cursor_wrap(var);
	return (2);
}

/*
** Fonction executee lors d'un appui sur retour arriere
** on bouge le curseur sur le caractere precedent
*/
int			erase_char(t_var *var)
{
	size_t			len;
	unsigned long 	i;

	len = ft_strlen(var->line.s);
	move_to_previous_char(var);
	var->line.s[var->line.pos] = '\0';
	set_str_cap("dc");
	i = var->line.pos;
	while (i < len)
	{
		var->line.s[i] = var->line.s[i + 1];
		i++;
	}
	var->line.s[i] = '\0';
	return (2);
}

/*
** Fonction executee lors d'un appui sur delete / suppr
*/
int			delete_char(t_var *var)
{
	size_t			len;
	unsigned long 	i;

	len = ft_strlen(var->line.s);
	var->line.s[var->line.pos] = '\0';
	set_str_cap("dl");
	i = var->line.pos;
	while (i < len)
	{
		var->line.s[i] = var->line.s[i + 1];
		i++;
	}
	var->line.s[i] = '\0';
	return (2);
}


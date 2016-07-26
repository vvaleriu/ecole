/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 12:48:19 by vincent           #+#    #+#             */
/*   Updated: 2016/07/19 22:29:53 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				is_ant_number(t_lemin_var *var, char *line)
{
	if (ft_strchr(line, '-') || ft_strchr(line, ' '))
		return (0);
	var->ant_nb = ft_atoi(line);
	return (1);
}

static	void	free_split_memory(char ***split)
{
	ft_strdel(&(*split[0]));
	free(*split);
	*split = NULL;
}

/*
** parse le fichier recu en entree.
** S'il repere une ligne "start" ou "end", elle change son flag statique en
** consequence afin que le traitement de la prochaine ligne prenne en compte
** cette information
*/
int				parse(t_lemin_var *var, char *line)
{
	static t_parser_info 	pi = {0, 0, };
	char					**split;

	if (!ft_strcmp(line, "##start"))
		return ((pi.is_start = 1));
	if (!ft_strcmp(line, "##end"))
		return ((pi.is_end = 1));
	if (!ft_strncmp(line, "#", 1))
		return (1);
	if (is_ant_number(var, line))
		return (1);
	split = ft_strsplit(line, ' ');
	if (ft_strarray_len(split) > 1)
		parse_room(var,split, &pi);
	else
	{
		free_split_memory(&split);
		split = ft_strsplit(line, '-');
		parse_link(var, split);
	}
	free_split_memory(&split);
	return (1);
}
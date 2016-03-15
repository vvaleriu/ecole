/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_termcaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:38:06 by vincent           #+#    #+#             */
/*   Updated: 2016/03/15 12:36:46 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		print_term_status(t_var *var)
{
	FILE *fp;

	fp = fopen("./debug_term.txt", "a+");
	fprintf(fp, "line->pos : %4d | POS_X POS_Y : (%d,%d)\n", \
	var->line.pos, var->conf->cur_pos[0], var->conf->cur_pos[1]);
	fclose(fp);
}

void		print_term_set_cap(char *str)
{
	FILE *fp;

	fp = fopen("./debug_term.txt", "a+");
	if (ft_strcmp(str, "im") && ft_strcmp(str, "ei") && ft_strcmp(str, "te")\
		&& ft_strcmp(str, "cd"))
		fprintf(fp, "--- CAP : %s ---\n", str);
	fclose(fp);
}
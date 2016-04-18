/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:15:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/18 07:58:43 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

/*
** ===============================
**		DEBUGGAGE INIT_FUNCTION
** ===============================
*/
void		check_tabs_init(t_var *var)
{
	int		i;

	i = -1;
	ft_printf("---------------------- TABLEAU DES LEXERS\n");
	while (++i < LEX_NB)
		ft_printf("Adresse lex[%d].f [%s]: %p\n", i, var->lex[i].s,\
			var->lex[i].f);
	i = -1;
	ft_printf("---------------------- TABLEAU DES BUILTINS\n");
	while (++i < BIN_NB)
		ft_printf("Adresse bin[%d].f [%s]: %p\n", i, var->bin[i].na,\
			var->bin[i].f);
	i = -1;
	ft_printf("---------------------- TABLEAU DES EXE\n");
	while (++i < OPS_NB)
		ft_printf("Adresse ef[%d]\n", var->ef[i]);
}

/*
** ===============================
**		DEBUGGAGE MAIN
** ===============================
*/

void		deb_print_first_list(t_list *list)
{
	ft_putstr("______________DEBUT (first list)_\n");
	while (list)
	{
		ft_printf("element de la liste : %s\n", (char *)list->content);
		list = list->next;
	}
	ft_putstr("______________FIN_____________\n\n");

}

void		deb_print_token_list(t_list *list)
{
	t_token		*tmp;
	const char	*a[9];

	a[0] = ";";
	a[1] = "|";
	a[2] = "<";
	a[3] = ">";
	a[6] = "<<";
	a[7] = ">>";
	a[4] = "&&";
	a[5] = "||";
	a[8] = "CMD";
	ft_putstr("______________DEBUT (token_list)_\n");
	while (list)
	{
		tmp = (t_token *)list->content;
		ft_printf("No : %d, Pty : %d, ", tmp->no, tmp->pty);
		if (tmp->exe == NULL)
			ft_printf("%s\n", a[tmp->no]);
		else
			ft_printf("%s : %s\n", "CMD", tmp->exe[0]);
		if (!list->next)
			ft_putstr("______________FIN_____________\n\n");
		list = list->next;
	}
}

void		print_token(t_token *tk)
{
	const char	*a[9];

	a[0] = ";";
	a[1] = "|";
	a[2] = "<";
	a[3] = ">";
	a[6] = "<<";
	a[7] = ">>";
	a[4] = "&&";
	a[5] = "||";
	a[8] = "CMD";
	ft_printf("print_token - Op : %d, pty : %d, sym : %s\n", tk->no, tk->pty, a[tk->no]);
	if (tk->exe)
		ft_putstr_array(tk->exe);
}

void		check_tree(t_token *root)
{
	if (root)
	{
		if (root->left)
			check_tree(root->left);
		if (root->right)
			check_tree(root->right);
		print_token(root);
	}
	else
		ft_printf("liste vide\n");
}

/*
** ===============================
**		DEBUGGAGE TERMCAPS
** ===============================
*/

void		print_term_status(t_var *var)
{
	FILE *fp;

	fp = fopen("./debug_term.txt", "a+");
	fprintf(fp, "line->pos : %4d | POS_X POS_Y : (%d,%d)\n", \
	var->line.pos, var->conf->cur_pos[0], var->conf->cur_pos[1]);
	fclose(fp);
}

void		print_term_status1(t_var *var, char *tmp)
{
	FILE *fp;

	fp = fopen("./debug_term.txt", "a+");
	fprintf(fp, "%s line->pos : %4d | POS_X POS_Y : (%d,%d)\n", \
	tmp, var->line.pos, var->conf->cur_pos[0], var->conf->cur_pos[1]);
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

void		print_trackers_status(t_var *var)
{
	ft_printf("strlen(%u), line.pos(%d), cur_pos(%d, %d)",\
		ft_strlen(LN_S), LN_POS, CUR_POS_X, CUR_POS_Y);
}

void			processus_end_analysis(int status)
{
	ft_printf("Le fils s'est termine normalement : %s\n", WIFEXITED(status) ?\
		"vrai" : " faux");
	ft_printf("Code de sortie du fils : %d\n", WEXITSTATUS(status));
	ft_printf("Le fils s'est terminé à cause d'un signal.  : %s\n", \
		WIFSIGNALED(status) ? "vrai" : " faux");
	ft_printf("Le fils s'est termine normalement : %s\n", WIFEXITED(status) \
		? "vrai" : " faux");
}

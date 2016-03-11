/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:07:13 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/11 23:20:25 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>
#include <stdio.h>

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
	while (++i < 7)
		ft_printf("Adresse ef[%d]\n", var->ef[i]);
}

/*
** initialise les pointeurs a NULL
** remplit les tableaux de fonctions de lexing / parsing / execution
** copie l'environnement
** on initialise le buffer contenant la ligne actuelle avec un taille donnee
** ainsi que renseignement de la taille maxi du buffer
*/
void		init_function(t_var *var, char **envp)
{
	var->root = NULL;
	var->conf = (t_tconf *)(ft_memalloc(sizeof(*(var->conf))));
	var->line.s = ft_strnew(CMD_LENGTH);
	var->line.max = CMD_LENGTH;
	var->line.pos = 0;
	var->hist.cur = NULL;
	var->hist.start = NULL;
	var->hist.tmp = NULL;
	fill_lex_ft(var->lex);
	ft_fill_tab(var->bin);
	ft_copy_env(var, envp);
	fill_exec_funct_array(var->ef);
}

/*
** initialisation des fonctions de lexing via remplissage du tableau
*/
void		fill_lex_ft(t_lexing_ft *lex)
{
	lex[0].s = ";";
	lex[0].f = lex_semicon;
	lex[1].s = "<";
	lex[1].f = lex_small;
	lex[2].s = ">";
	lex[2].f = lex_big;
	lex[3].s = "|";
	lex[3].f = lex_pipe;
	lex[4].s = NULL;
	lex[4].f = lex_space;
	lex[5].s = NULL;
	lex[5].f = lex_char;
}

/*
** remplissage du tableau des fonctions incluses dans le terminal
*/
void		ft_fill_tab(t_builtin *bin)
{
	bin[0].na = "cd";
	bin[0].f = &ft_cd;
	bin[1].na = "setenv";
	bin[1].f = &ft_setenv;
	bin[2].na = "unsetenv";
	bin[2].f = &ft_unsetenv;
	bin[3].na = "env";
	bin[3].f = &ft_env;
	bin[4].na = "exit";
	bin[4].f = &ft_exit;
}

/*
** remplissage du tableau des fonctions d'execution de l'arbre des commandes
*/
void		fill_exec_funct_array(int (*ef[])(struct s_var *, t_token *))
{
	ef[OPS_SEMIC] = exe_semi;
	ef[OPS_PIPE] = exe_pipe;
	ef[OPS_RIN] = exe_redir_in;
	ef[OPS_ROUT] = exe_redir_out;
	ef[OPS_DRIN] = exe_redir_in;
	ef[OPS_DROUT] = exe_redir_out;
	ef[OPS_EXEC] = exe_command;
}

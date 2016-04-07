/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 16:07:13 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:39:57 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>
#include <stdio.h>

static void		init_values(t_var *var)
{
	var->root = NULL;
	var->list = NULL;
	var->conf = (t_tconf *)(ft_memalloc(sizeof(*(var->conf))));
	var->hist.cur = NULL;
	var->hist.start = NULL;
	var->hist.tmp = NULL;
	var->line.tmp = NULL;
	var->line.quote = '\0';
	var->errstr = NULL;
	var->line.heredoc = 0;
	var->tenv = NULL;
	LN_S = NULL;
	LN_TMP = NULL;
	LN_CPY = NULL;
	ABORD = 0;
	PROMPT_LEN = PROMPT_LEN_VALUE;
	CLIST = NULL;
}

/*
** initialise les pointeurs a NULL
** remplit les tableaux de fonctions de lexing / parsing / execution
** copie l'environnement
** on initialise le buffer contenant la ligne actuelle avec un taille donnee
** ainsi que renseignement de la taille maxi du buffer
*/

void			init_function(t_var *var, char **envp)
{
	init_values(var);
	if (err_int(-1, ft_copy_env(var, envp), ERR_NO_ENV, 0) < 0 || !isatty(0))
	{
		var->errstr = ERR_NO_ENV;
		ft_exit(NULL, var);
	}
	fill_lex_ft(var->lex);
	ft_fill_tab(var->bin);
	fill_exec_funct_array(var->ef);
}

/*
** initialisation des fonctions de lexing via remplissage du tableau
*/

void			fill_lex_ft(t_lexing_ft *lex)
{
	lex[0].s = ";";
	lex[0].f = lex_semicon;
	lex[1].s = "<";
	lex[1].f = lex_small;
	lex[2].s = ">";
	lex[2].f = lex_big;
	lex[3].s = "|";
	lex[3].f = lex_pipe;
	lex[4].s = "&";
	lex[4].f = lex_and;
	lex[5].s = NULL;
	lex[5].f = lex_space;
	lex[6].s = NULL;
	lex[6].f = lex_char;
}

/*
** remplissage du tableau des fonctions incluses dans le terminal
*/

void			ft_fill_tab(t_builtin *bin)
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
	bin[5].na = "echo";
	bin[5].f = &ft_echo;
}

/*
** remplissage du tableau des fonctions d'execution de l'arbre des commandes
*/

void			fill_exec_funct_array(int (*ef[])(struct s_var *, t_token *))
{
	ef[OPS_SEMIC] = exe_semi;
	ef[OPS_PIPE] = exe_pipe;
	ef[OPS_RIN] = exe_redir_in;
	ef[OPS_ROUT] = exe_redir_out;
	ef[OPS_AND] = exe_and;
	ef[OPS_OR] = exe_or;
	ef[OPS_DRIN] = exe_dredir_in;
	ef[OPS_DROUT] = exe_redir_out;
	ef[OPS_EXEC] = exe_command;
}

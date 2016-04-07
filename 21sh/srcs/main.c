/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:42:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 09:36:05 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_minishell2.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int			main(int ac, char **av, char **envp)
{
	t_var	*var;

	(void)ac;
	(void)av;
	var = get_instance();
	init_function(var, envp);
	init_terminal(var);
	sig_catcher();
	while (18)
	{
		ft_putstr_fd("$>", var->conf->wfd);
		set_str_cap("sc");
		terminal_input_mode(var->conf);
		read_key(var);
		terminal_execute_mode(var->conf);
		proceed_to_execution(var);
	}
	ft_strdel(&(var->line.cpy));
	return (0);
}

/*
** Execute tout le processus d'execution de la commande jusqu'au nettoyage des
*/
void 		proceed_to_execution(t_var *var)
{
	var->list = lexer(var, var->lex);
	// deb_print_first_list(var->list);
	var->list = create_tokens(var->list);
	// deb_print_token_list(var->list);
	var->root = parser(var->list);
	// check_tree(var->root);
	// ft_putstr("___________________________\n");
	execute_tree(var, var->root);
	clean_tree(var->root);
	var->root = NULL;
	var->list = NULL;
	clean_line_pointers(var);
}

void		clean_line_pointers(t_var *var)
{
	ft_strdel(&(LN_TMP));
	LN_S = NULL;
}

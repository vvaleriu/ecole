/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:42:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/22 22:18:49 by vincent          ###   ########.fr       */
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
		ft_putstr_fd("$>", var->conf->fd);
		set_str_cap("sc");
		terminal_input_mode(var->conf);
		read_key(var);
		terminal_execute_mode(var->conf);
		var->list = lexer(var->line.s, var->lex);
		deb_print_first_list(var->list);
		var->list = create_tokens(var->list);
		deb_print_token_list(var->list);
		var->root = parser(var->list);
        check_tree(var->root);
		execute_tree(var, var->root);
		clean_tree(var->root);
		var->root = NULL;
		ft_strdel(&(var->line.s));
	}
	ft_strdel(&(var->line.cpy));
	return (0);
}

/*void		print_prompt_routine(t_var *var)
{

}*/

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
	const char	*a[6];

	a[0] = ";";
	a[1] = "|";
	a[2] = "<";
	a[3] = ">";
	a[4] = "<<";
	a[5] = ">>";
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
	const char	*a[6];

	a[0] = ";";
	a[1] = "|";
	a[2] = "<";
	a[3] = ">";
	a[4] = "<<";
	a[5] = ">>";
	ft_printf("pt_token(main)Op : %d, pty : %d, exe : ", tk->no, tk->pty);
	if (!tk->exe)
		ft_printf("%s\n", a[tk->no]);
	else
		ft_putstr_array(tk->exe);
	ft_putchar('\n');
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
int main()
{
    char **ret;

    ret = ft_strsplit("coco bongo caca banga", ' ');
    lol(&ret, 1);
    ft_putstr_array(ret);
    ft_strarray_del(&ret);
    return 0;
}*/

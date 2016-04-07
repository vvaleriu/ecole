/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_semi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:21:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 09:39:36 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <libft.h>
#include <ft_minishell2.h>

/*
** Execute l'arbre sans fork car il faut executer un Builtin
*/
static int		exe_semi_builtins(t_var *var, t_token *tk)
{
	int		status;

	status = execute_tree(var, tk->left);
	if (!WEXITSTATUS(status))
		status = execute_tree(var, tk->right);
	else
		execute_tree(var, tk->right);
	return (status);
}

/*
** Execute l'arbre de maniere classique avec un fork car il n'y a pas de Builtin
** a executer
*/
static int		exe_semi_normal(t_var *var, t_token *tk)
{
	pid_t	father;
	int		status;

	father = fork();
	if (!father)
		exit(execute_tree(var, tk->left));
	else
	{
		waitpid(father, &status, 0);
		if (!WEXITSTATUS(status))
			status = execute_tree(var, tk->right);
		else
			execute_tree(var, tk->right);
	}
	return (status);
}

/*
**	On execute la fonction qui corespond
** !father : child process
** father : wait for the child process to finish first
**
** Fork realise une copie des variables. De fait, changer de repertoire dans le
** processus fils n'affectera pas le processus pere. Il en va de meme pour les
** variables d'environnement.
** Pour pallier le probleme, lorsqu'on rentre dans l'execution d'un semi, si la
** branche gauche est une fonction builtins, elle ne sera pas executee dans un
** fork, mais directement dans le processus principal.
*/
int		exe_semi(t_var *var, t_token *tk)
{
	int		status;

	if (tk->left->exe != NULL &&tk->left->exe[0] != NULL &&\
		is_builtin(tk->left->exe[0], var))
		status = exe_semi_builtins(var, tk);
	else
		status = exe_semi_normal(var, tk);
	return (status);
}

void	processus_end_analysis(int status)
{
	ft_printf("Le fils s'est termine normalement : %s\n", WIFEXITED(status) ? "vrai" : " faux");
	ft_printf("Code de sortie du fils : %d\n", WEXITSTATUS(status));
	ft_printf("Le fils s'est terminé à cause d'un signal.  : %s\n", WIFSIGNALED(status) ? "vrai" : " faux");
	ft_printf("Le fils s'est termine normalement : %s\n", WIFEXITED(status) ? "vrai" : " faux");
}
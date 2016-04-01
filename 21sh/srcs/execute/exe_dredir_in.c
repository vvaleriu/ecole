/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_dredir_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/02 00:36:31 by vincent          ###   ########.fr       */
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
** imprime la bonne valeur sur le prompteur lorsqu'on doit fermer une quote
*/
static void	print_heredoc_prompt(t_var *var)
{
	move_to_next_line(var);
	set_str_cap("sc");
	terminal_execute_mode(var->conf);
	PROMPT_LEN = ft_strlen("heredoc>");
	ft_printf("heredoc>");
	set_str_cap("sc");
	terminal_input_mode(var->conf);
}

/*
** retourne 0 si n'a pas trouve la quote fermante
** retourn 1 si c'est bon
** tmp : lecture deja faite de l'entree et sauvegardee
** line : chaine de caractere a peine lue
** on ne free pas LN-TMP car il pointe sur une zone qui sera liberee plus tard
*/
int 		check_for_ending_sequence(t_var *var, char **tmp, char **line)
{

	if (ft_strcmp(*line, LN_TMP))
		return (0);
	PROMPT_LEN = PROMPT_LEN_VALUE;
	LN_TMP = *tmp;
	move_to_next_line(var);
	LN_HEREDOC = 0;
	return (1);
}

/*
** buf : pointeur sur la position sur laquelle on se trouve de la ligne du
** terminal
** s : ligne du terinal a l'endroit ou on repere la quote
** tmp : partie ligne que l'on a deja enregistree
** - on si on ne trouve pas de quote fermante, alors on reboucle sur la fonction
** 	affichant le prompteur pour fermer la quote
**	- Si on ne l'a pas trouvee, alors on rentre dans missing_quote_loop
**	- Sinon on continue le lexing classique
*/
void		dredir_loop(t_var *var)
{
	static char		*tmp = NULL;
	static char		*del = NULL;

	if (tmp == NULL || !check_for_ending_sequence(var, &tmp, &(LN_S)))
	{
		del = tmp;
		tmp = (tmp != NULL ? ft_strjoin(tmp, "\n") : tmp);
		ft_strdel(&del);
		del = tmp;
		tmp = ft_strjoin(tmp, LN_S);
		ft_strdel(&del);
		//ft_strdel(&(LN_S));
		print_heredoc_prompt(var);
		read_key(var);
	}
}

/*
** Si on a bien une chaine de fin
** - Alonrs on recupere l'entree via dredir-loop qui va enregistrer l'entree
** standard dans LN_TMP.
*/
int		exe_dredir_in(t_var *var, t_token *tk)
{
	pid_t	father;
	int		status;
	int		fd[2];
	int		saved_fds[2];

	father = fork();
	save_std_fds(saved_fds);
	status = pipe(fd);
	if (!father)
	{
		if ((LN_TMP = tk->right->exe[0]) != NULL && !status)
		{
			LN_HEREDOC = 1;
			dredir_loop(var);
			ft_putstr_fd(LN_TMP, fd[1]);
			ft_putstr_fd("\0", fd[1]);
			dup2(fd[0], 0);
			ft_strdel(&(LN_TMP));
			LN_TMP = LN_S;
			exit(execute_tree(var, tk->left));
		}
		else
			exit(0);
	}
	else
	{
		waitpid(father, &status, 0);
		close(fd[0]);
		close(fd[1]);
		restore_std_fds(saved_fds);
	}
	return (WEXITSTATUS(status));
}

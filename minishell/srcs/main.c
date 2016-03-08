/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 15:42:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/08 15:07:17 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_minishell2.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>




static int		end_of_file1(t_str_prop *p, char **line)
{
	ft_strdel(&(p->buf));
	*line = p->file;
	if (ft_strlen(p->file))
	{
		p->rd = -3;
		return (1);
	}
	return (0);
}

int				get_next_line1(int const fd, char **line)
{
	static t_str_prop	p = {-2, NULL, NULL, NULL, NULL};

	if (p.rd == -3)
		return (0);
	p.buf = (p.rd == -2 ? (char *)malloc(sizeof(char) * GNL_BUFFER + 1) : p.buf);
	if (fd < 0 || GNL_BUFFER < 1 || !p.buf)
		return (-1);
	ft_strdel(&p.tmp);
	while ((p.end = ft_strchr(p.file, '\n')) == NULL && p.rd != 0)
	{
		ft_bzero((void *)p.buf, GNL_BUFFER + 1);
		p.rd = read(fd, p.buf, GNL_BUFFER);
		if (!p.rd)
			return (end_of_file1(&p, line));
		p.tmp = p.file;
		p.file = ft_strjoin(p.file, p.buf);
		ft_strdel(&p.tmp);
	}
	*p.end = '\0';
	*line = p.tmp = p.file;
	p.file = ft_strdup(p.end + 1);
	return (1);
}





int			main(int ac, char **av, char **envp)
{
	t_var	var;

	(void)ac;
	(void)av;
	init_function(&var, envp);
	signal(SIGINT, sig_handler);
	signal(SIGTSTP, SIG_IGN);
	while (18)
	{
		ft_putstr("$>");
		//if (get_next_line(0, &(var.line)) == -2)
		if (!get_next_line1(0, &(var.line)))
			ft_exit(NULL, (void *)&var);
		var.list = lexer(var.line, var.lex);
		var.list = create_tokens(var.list);
		var.root = parser(var.list);
        check_tree(var.root);
		execute_tree(&var, var.root);
		clean_tree(var.root);
		var.root = NULL;
	}
	return (0);
}

void		deb_print_first_list(t_list *list)
{
	while (list)
	{
		ft_printf("element de la liste : %s\n", (char *)list->content);
		list = list->next;
	}
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
	ft_putstr("______________DEBUT_____________\n");
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
	int			i;
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
	{
		i = 0;
		while (tk->exe[i])
		{
			ft_printf("%s ", tk->exe[i]);
			i++;
		}
	}
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
		//print_token(root);
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

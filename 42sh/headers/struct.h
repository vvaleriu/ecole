/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:24:48 by graybaud          #+#    #+#             */
/*   Updated: 2016/05/27 11:24:52 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <libft.h>

/*
** LEX_NB		: Nombre de fonctions pour le lexer
** BIN_NB		: Number of personal builtin functions
** OPS_NB		: Nombre d'operations possibles
*/

# define LEX_NB			7
# define BIN_NB			6
# define OPS_NB			9

typedef struct s_var	t_var;

/*
** tokens to be executed
** no 	: operation number
** pty	: operation's priority
** exe	: operation binary and arguments id necessary
*/

typedef struct			s_token
{
	int				no;
	int				pty;
	char			**exe;
	struct s_token	*left;
	struct s_token	*right;
}						t_token;

/*
** struct lexing: token is type while priority is the operator's / argument's
** precedence
*/

typedef struct			s_lexing_ft
{
	char	*s;
	void	(*f)(t_var *var, char **, t_list **alst);
}						t_lexing_ft;

/*
** struct pcom: token is type while priority is the operator's / argument's
** precedence
*/

typedef struct			s_builtin
{
	char	*na;
	int		(*f)(char **, void *);
}						t_builtin;
/*
** Structure representant la ligne de commande actuelle.
** line : ligne de commande
** tmp : sauvegarde temporaire de la ligne, utile pour les quotes non fermees
** cpy : chaine de caractere copiee par l'utilisateur
** position : sur quel caractere de cette ligne le curseur se trouve
** max : longueur max de la chaine avant de devoir realloc
** prompt_len : longeur du prompt (parfois "$>" parfois "quote>")
** quote : si different de \0 alors on a une quote non ferme et on waitclose
*/
typedef struct			s_cmd_line
{
	char	*s;
	char	*tmp;
	char	*cpy;
	int		pos;
	size_t	max;
	int		prompt_len;
	char	quote;
	int		heredoc;
}						t_cmd_line;

/*
** Structure representant l'historique des commandes entrees
** start : pointeur sur le debut de cette liste (LIFO)
** position actuelle dans la liste
*/
typedef struct			s_cmd_hist
{
	t_dlist	*start;
	t_dlist *cur;
	char	*tmp;
}						t_cmd_hist;

/*
**			GENERAL VARIABLES STRUCTURE
** -
** bin : array of builtins structures (set a app start)
** line : current command line
** hist : liste de l'hitorique des commandes rentrees.
** list :
** root : root of the token tree
** lex : array of lexing functions
** conf : conf structure of a terminal (see ft_termcaps.h)
** clist : liste contenant les noms des fichiers pour l'autocompletion
** key_buf : buffer contenant la suite de caractere qui represente
** la touche appuyee
** ef : function that execute the necessary token
*/

struct					s_var
{
	t_builtin		bin[BIN_NB];
	t_cmd_line		line;
	t_cmd_hist		hist;
	t_list			*list;
	t_token			*root;
	t_lexing_ft		lex[LEX_NB];
	t_tconf			*conf;
	t_dlist			*clist;
	int				abord;
	char			**tenv;
	char			key_buf[SEL_KEY_SIZE];
	char			*errstr;
	int				(*ef[OPS_NB])(t_var *, t_token *);
};

#endif

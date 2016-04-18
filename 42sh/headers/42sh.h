/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:34:06 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/18 09:43:14 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

# include <libft.h>
# include <ft_termcaps.h>
# include <ft_sh_errors.h>

/*
** LEX_NB		: Nombre de fonctions pour le lexer
** BIN_NB		: Number of personal builtin functions
** OPS_NB		: Nombre d'operations possibles
*/

# define CMP			ft_strncmp
# define LEN			ft_strlen
# define LEX_NB			7
# define BIN_NB			6
# define OPS_NB			9

/*
** LONGUEUR DU PROMPT. UTILE dans init_line_struct, pour definir la
** position de depart du curseur
** HIST_LEN : taille de la liste de l'historique
*/
# define PROMPT_LEN			var->line.prompt_len
# define PROMPT_LEN_VALUE	2
# define HIST_LEN			500

/*
** HELPERS
*/
# define LN_S			var->line.s
# define LN_TMP			var->line.tmp
# define LN_CPY			var->line.cpy
# define LN_POS			var->line.pos
# define LN_QUOTE		var->line.quote
# define LN_HEREDOC		var->line.heredoc
# define CLIST			var->clist
# define ABORD			var->abord
# define FD_IN			var->conf->rfd
# define FD_OUT			var->conf->wfd
# define CUR_POS_X		var->conf->cur_pos[0]
# define CUR_POS_Y		var->conf->cur_pos[1]
# define WIN_X			var->conf->w.ws_col
# define WIN_Y			var->conf->w.ws_row
# define LEX_CHAR_NB	6

/*
** OPS_NB	nb of ops :
** OPS_SEMIC	";":	0
** OPS_PIPE		"|":	1
** OPS_RIN		"<":	2
** OPS_ROUT 	">":	3
** OPS_AND		"&&":	4
** OPS_AND		"||":	5
** OPS_DRIN		"<<":	6
** OPS_DROUT	">>":	7
** --
** Priorite : ordre de priorite associe a une operation
** Permet de construire l'arbre en sachant quelle operations passent
** avant ou apres les autres
** PTY_NB			4 : nombre de priorite existante
*/
# define OPS_SEMIC		0
# define OPS_PIPE		1
# define OPS_RIN		2
# define OPS_ROUT 		3
# define OPS_AND		4
# define OPS_OR			5
# define OPS_DRIN		6
# define OPS_DROUT		7
# define OPS_EXEC		8

/*
** Priorite : ordre de priorite associe a une operation
** Permet de construire l'arbre en sachant quelle operations passent
** avant ou apres les autres
** PTY_NB			4 : nombre de priorite existante
*/
# define PTY_NB			4
# define PTY_SEMIC		0
# define PTY_AND		0
# define PTY_OR			0
# define PTY_PIPE		1
# define PTY_RIN		2
# define PTY_ROUT 		2
# define PTY_DRIN		2
# define PTY_DROUT		2
# define PTY_EXEC		3

/*
** CMD_LENGTH : taille du buffer d'une ligne de commande par defaut
*/
# define CMD_LENGTH		325

typedef struct s_var	t_var;

/*
** tokens to be executed
** no 	: operation number
** pty	: operation's priority
** exe	: operation binary and arguments id necessary
*/

typedef struct		s_token
{
	int				no;
	int				pty;
	char			**exe;
	struct s_token	*left;
	struct s_token	*right;
}					t_token;

/*
** struct lexing: token is type while priority is the operator's / argument's
** precedence
*/

typedef struct		s_lexing_ft
{
	char	*s;
	void	(*f)(t_var *var, char **, t_list **alst);
}					t_lexing_ft;

/*
** struct pcom: token is type while priority is the operator's / argument's
** precedence
*/

typedef struct		s_builtin
{
	char	*na;
	int		(*f)(char **, void *);
}					t_builtin;
/*
** Structure representant la ligne de commande actuelle.
** line : ligne de commande
** tmp : sauvegarde temporaire de la ligne, utile pour les quotes non fermees
** cpy : chaine de caractere copiee par l'utilisateur
** position : sur quel caractere de cette ligne le curseur se trouve
** max : longueur max de la chaine avant de devoir realloc
** prompt_len : longeur du prompt (parfois "$>" parfois "quote>")
** quote : si different de \0 alors on a une quote non ferme et on attend sa fermeture
*/
typedef struct		s_cmd_line
{
	char	*s;
	char	*tmp;
	char	*cpy;
	int		pos;
	size_t	max;
	int		prompt_len;
	char	quote;
	int		heredoc;
}					t_cmd_line;

/*
** Structure representant l'historique des commandes entrees
** start : pointeur sur le debut de cette liste (LIFO)
** position actuelle dans la liste
*/
typedef struct		s_cmd_hist
{
	t_dlist	*start;
	t_dlist *cur;
	char	*tmp;
}					t_cmd_hist;

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

typedef struct		s_var
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
	int				(*ef[OPS_NB])(struct s_var *, t_token *);
}					t_var;

/*
** 			INITIALISATION FUNCTIONS
*/

int			chk_stdin();
void		init_function(t_var *var, char **envp);
void		ft_fill_tab(t_builtin *bin);
void		fill_lex_ft(t_lexing_ft *lex);
int			ft_copy_env(t_var *var, char **envp);
void		fill_env_array(t_var *var);
void		fill_lex_ft_tab(t_lexing_ft *lex);
void		fill_exec_funct_array(int (*ef[])(struct s_var *, t_token *));

/*
** 			LEXING FUNCTIONS
*/

t_list		*lexer(t_var *var, t_lexing_ft *lex);
void		lex_semicon(t_var *var, char **buf, t_list **alst);
void		lex_small(t_var *var, char **buf, t_list **alst);
void		lex_big(t_var *var, char **buf, t_list **alst);
void		lex_pipe(t_var *var, char **buf, t_list **alst);
void		lex_space(t_var *var, char **buf, t_list **alst);
void		lex_and(t_var *var, char **buf, t_list **alst);
void		lex_char(t_var *var, char **buf, t_list **alst);
void		lex_quote(t_var *var, char **buf, t_list **alst);
void		missing_quote_loop(t_var *var, char *s, t_list **alst);
void		lex_aggregation(char **buf, t_list **alst);
void		lex_alnum(char **buf, t_list **alst);

/*
** 			PARSING FUNCTIONS
*/

int			is_fd_aggregation(char *str);
int			get_op_no(char *s);
int			get_op_pty(int no);
char		*del_quotes(void **str);
char		**create_exe(t_list **list);
t_list		*create_tokens(t_list *alst);
t_token		*parser(t_list *list);

/*
**			EXECUTION FUNCTIONS
*/

void		proceed_to_execution(t_var *var);
int			execute_tree(t_var *var, t_token *tk);
void		clean_line_pointers(t_var *var);
void		processus_end_analysis(int status);
int			exe_semi(t_var *var, t_token *tk);
int			exe_and(t_var *var, t_token *tk);
int			exe_or(t_var *var, t_token *tk);
int			exe_pipe(t_var *var, t_token *tk);
int			exe_redir_in(t_var *var, t_token *tk);
int			exe_dredir_in(t_var *var, t_token *tk);
void		dredir_loop(t_var *var);
int			stdfd_redir(t_token *tk);
int			exe_redir_out(t_var *var, t_token *tk);
char		*get_path(char *exe, char **env);
void		execute_back_quote(t_var *var, char **arg);
int			exe_command(t_var *var, t_token *tk);

/*
**			SIGNAL HANDLERS
*/

void		sig_catcher(void);
void		sig_catcher_fork(void);
void		sig_handler(int signo);
void		sig_handler_fork(int signo);
void		go_background(int signo);
void		go_foreground(int signo);

/*
**			COMPLETION
*/

int			completion(t_var *var);
int			look_for_exe(t_var *var);
int			currently_on_a_word(t_var *var);
char		*get_current_word(t_var *var);
void		delete_completion_list(void *content, size_t size);
void		get_word_and_folder(char *ret[], char *word);
t_dlist		*create_exe_list(t_var *var, char *word);
t_dlist		*create_files_list(char *word);

/*
**			BINS
*/
int			is_builtin(char *exe, t_var *var);
int			ft_cd(char **exe, void *var);
int			ft_env(char **exe, void *var);
int			ft_setenv(char **exe, void *var);
int			ft_unsetenv(char **exe, void *var);
int			ft_exit(char **exe, void *var);
int			ft_echo(char **exe, void *var);
int			find_env(char *exe, char **env);

/*
**			INPUTS
*/
void		save_current_input(t_var *var);
int			add_to_history(t_var *var);
int			history_next(t_var *var);
int			history_prev(t_var *var);

/*
**			TOOLS
*/
t_var		*get_instance(void);
t_tconf		*get_conf(void);
int			is_text(char c);
int			is_filename(char c);
void		free_all_list(t_list *alst);
void		clean_tree(t_token *root);
void		clean_env(t_var *var);
void		clean_term_conf(t_var *var);
void		clean_line(t_var *var);
void		clean_clist(t_var *var);
void		clean_var(t_var *var);
void 		clean_history(t_var *var);
void		save_std_fds(int fds[2]);
void		restore_std_fds(int fds[2]);
void		print_token(t_token *tk);
void		deb_print_first_list(t_list *list);
void		deb_print_token_list(t_list *list);
void		check_tree(t_token *root);
char		*get_env_value(char *var, char **env);
void		check_tabs_init(t_var *var);
void		init_line_struct(t_var *var);
void		update_line_struct(t_var *var);
void		del_hist_el(void *p, size_t size);
void		get_cursor_position(void);

#endif

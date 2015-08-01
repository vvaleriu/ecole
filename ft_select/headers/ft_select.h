/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:33:47 by vincent           #+#    #+#             */
/*   Updated: 2015/08/01 01:52:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

# define KEY_SIZE		3

/*
**	TERMCAPS CAPS List
**
**	------- GRAPHIC
**	enable / disable underline:	us / ue
**	enable			 reverse mode: mr
**	------- CURSOR
**	move cursor left one column: le
**	move cursor right one column: nd
**	move cursor to next line: nw
**	says that `le' may be used in column
**		zero to move to the last column of the preceding line: bw
*/

/*
**	ERRORS
*/

# define ERR_SET_TERM_CAPS	"Can't setup terminal capabilities."
# define ERR_TERM_DB		"Could not access the termcap data base.\n"
# define ERR_TERM_UNDEF		"Terminal type is not defined.\n"
# define ERR_TERM_CAP_UNDEF	"Terminal cap not found.\n"

typedef struct s_tconf	t_tconf;
typedef struct s_item	t_item;

/*
**	run: 1 program runs, 0 program has to quit
**	list: circular list of items
**	term_buffer	: stock le
**	w		: structure containing window's number of col and row 
**	def		: default terminal conf (restore at when leaves)
**	cur		: current conf to apply
*/

struct s_tconf
{
	int				run;
	t_dlist			*list;
	struct winsize	w;
	struct termios 	def;
	struct termios 	cur;
	char			term_buffer[2048];
};

/*
**	s: value of the selection
**	x: column position
**	y: row position
**	sel: item is selected
*/

struct s_item
{
	size_t			len;
	int				x;
	int				y;
	char			*s;
	short			sel;
};

/*
** GLOBAL TO HANDLE SIGNALS
*/

t_tconf				conf;

/*
** MAIN
*/

int					init_terminal(t_tconf *conf);
void				print_list(char **av);

/*
** SIGNALS MANAGER
*/


void				sig_handler(int signo);
void				sig_catcher();

/*
** TERM MANAGER
*/

int 				load_term_prop(t_tconf *conf);
void				get_screen_size(int signo);
int					change_term_attr(t_tconf *conf);
void				toggle_str_cap(char *cap_str);

/*
** KEY HANDLING
*/

int					get_key();
void				handle_arrow();
void				handle_return(t_tconf *conf);

/*
** TOOLS
*/
int					putchar_int(int c);
t_item				*new_item(char *s);
t_dlist				*build_list(char **list);

#endif

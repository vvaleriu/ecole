/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:33:47 by vincent           #+#    #+#             */
/*   Updated: 2016/03/03 12:09:01 by vvaleriu         ###   ########.fr       */
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

/*
** KEY_SIZE : size of the str to check when a key is pressed
** KEY_NUMBER : number of key actively defined and to check
** LIST_ST: first item of the list
** CUR_ITEM: current selected item on the list
*/

# define SEL_KEY_SIZE		3
# define KEY_NUMBER			9
# define LIST_ST			conf->list
# define CUR_ITM			conf->cur_item
# define LONGEST			ftsel[0]
# define ROWS				ftsel[1]
# define LIST_LEN			ftsel[2]
# define TMP				ftsel[3]
# define Y_OFFSET			ftsel[4]

# define KEY_TAB(i)			conf->keyman[i]
# define KLEFT				conf->keyman[0]
# define KRIGHT				conf->keyman[1]
# define KUP				conf->keyman[2]
# define KDOWN				conf->keyman[3]
# define KESC				conf->keyman[4]
# define KRET				conf->keyman[5]
# define KBKSP				conf->keyman[6]
# define KDEL				conf->keyman[7]
# define KSPACE				conf->keyman[8]

# define ESC 				4
# define RET				5

# define DOWN_ARROW			'B'
# define UP_ARROW			'A'
# define RIGHT_ARROW		'C'
# define LEFT_ARROW			'D'
/*
**	TERMCAPS CAPS List
**
**
** Enter fullscreen mode : ti: <Esc> 7 <Esc> [ ? 47 h
** Exit fullscreen mode :  te: <Esc> [ 2 J <Esc> [ ? 4 7 l <Esc> 8
**
**	------- GRAPHIC
**	enable / disable underline:	us / ue
**	enable			 reverse mode: mr
**	------- CURSOR
**	hide / show cursor: vi / ve
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

typedef struct s_tconf		t_tconf;
typedef struct s_item		t_item;
typedef struct s_key_man	t_key_man;

/*
** seq_len is used in ft_strncmp to know the length of the keysequence to check
** key sequence to identify
** function to execute when the corresponding key is pressed
*/

struct s_key_man
{
	size_t	seq_len;
	char 	seq[SEL_KEY_SIZE];
	int		(*f)(t_tconf *, char *);
};


/*
**	run: 1 program runs, 0 program has to quit
**	list: circular list of items
**	cur_item: item in the list the cursor is on
**	row: number of row of items
**	col: number of col of items
**	term_buffer	: stock le
**	w		: structure containing window's number of col and row 
**	def		: default terminal conf (restore at when leaves)
**	cur		: current conf to apply
*/

struct s_tconf
{
	int				run;
	t_dlist			*list;
	t_dlist			*cur_item;
	int				row;
	int				col;
	struct winsize	w;
	struct termios 	def;
	struct termios 	cur;
	char			term_buffer[2048];
	t_key_man		keyman[KEY_NUMBER];
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
** MAIN
*/
int					init_terminal(t_tconf *conf);
t_tconf 			*get_instance();
void				print_small_size_error();
void				print_list(t_tconf *conf);
void				build_list(t_tconf *conf, char **list);

/*
** KEY MANAGERS
*/
int					get_key(t_tconf *conf);
int					move_cursor(t_tconf *conf, char *key_buf);
int					delete_item(t_tconf *conf, char *key_buf);
int					select_item(t_tconf *conf, char *key_buf);
int					close_program(t_tconf *conf, char *key_buf);

/*
** SIGNALS MANAGER
*/
void				sig_catcher();
void				go_background(int signo);
void				go_foreground(int signo);

/*
** TERM MANAGER
*/
int 				load_term_prop(t_tconf *conf);
void				resize_list(int signo);
int					change_term_attr(t_tconf *conf);
void				set_str_cap(char *cap_str);
size_t				print_item(t_tconf *conf, t_dlist *elem, int x, int y);

/*
** TOOLS
*/
void				exit_clean(t_tconf *conf);
int					putchar_int(int c);
t_item				*new_item(char *s);
void				deb_list(t_tconf *conf);
void				del_list_elem(void *content, size_t size);
void 				move_to(int x, int y);

/*
** DEBUG
*/
void				deb_item(t_item *item);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:33:47 by vincent           #+#    #+#             */
/*   Updated: 2016/03/11 12:46:04 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAPS_H
# define FT_TERMCAPS_H

# include <libft.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** KEY_SIZE : size of the str to check when a key is pressed
** KEY_NUMBER : number of key actively defined and to check
** LIST_ST: first item of the list
** CUR_ITEM: current selected item on the list
*/

# define SEL_KEY_SIZE		4
# define KEY_NUMBER			10
# define CUR_X				conf->cur_pos[0]
# define CUR_Y				conf->cur_pos[1]
# define WIN_X				conf->w.ws_col
# define WIN_Y				conf->w.ws_row
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
# define KDEL				conf->keyman[6]
# define KBKSP				conf->keyman[7]
# define KHOME				conf->keyman[8]
# define KEND				conf->keyman[9]

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
typedef struct s_key_man	t_key_man;
typedef struct s_var		t_var;

/*
** seq_len is used in ft_strncmp to know the length of the keysequence to check
** key sequence to identify
** function to execute when the corresponding key is pressed
*/
struct s_key_man
{
	size_t	seq_len;
	char 	seq[SEL_KEY_SIZE];
	int		(*f)(t_var *var);
};

/*
**	cur_pos : current cursor position [0] : x, [1] : y
**	term_buffer	: stock le
**	w		: structure containing window's number of col and row 
**	def		: default terminal conf (restore at when leaves)
**	cur		: current conf to apply
** 	keyman : tableau de  structure permettant d'identifier la touche pressee
*/
struct s_tconf
{
	int				cur_pos[2];
	int				fd;
	struct winsize	w;
	struct termios 	def;
	struct termios 	cur;
	char			term_buffer[2048];
	t_key_man		keyman[KEY_NUMBER];
};

/*
** MAIN
*/
int					init_fd(int fd);
int					init_terminal(t_var *var);

/*
** TERM MANAGER
*/
int 				load_term_prop(t_tconf *conf);
int					change_term_attr(t_tconf *conf);
void				set_str_cap(char *cap_str);

/*
** KEY MANAGERS
*/
int					read_key(t_var *var);
int					return_command(t_var *var);
int					restore_terminal(t_var *var);
int					move_to_next_char(t_var *var);
int					move_to_previous_char(t_var *var);
int					move_cursor(t_var *var);
int					insert_char(t_var *var);
int					erase_char(t_var *var);
int					delete_char(t_var *var);
int					cursor_to_origin(t_var *var);

/*
** PRINTING
*/
void				ft_putchar_cursor(char c);
void				ft_putcstr_cursor(char *str);

/*
** TOOLS
*/
int					putchar_int(int c);
void				ft_putchar_cursor(char c);
void				ft_putstr_cursor(char *str);
void 				move_to(int x, int y);
void				update_win_size(int signo);

#endif

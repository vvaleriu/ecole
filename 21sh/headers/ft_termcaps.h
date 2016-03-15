/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:33:47 by vincent           #+#    #+#             */
/*   Updated: 2016/03/15 18:14:19 by vincent          ###   ########.fr       */
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
** - SEL_KEY_SIZE : size of the str to check when a key is pressed
** - KEY_NUMBER : number of key actively defined and to check. Nombre de touches
**	auxquelles sont associees des fonctions speciales.
** - ESC : case de la touche ESC dans le tableau de touches
** - RET : case de la touche RET dans le tableau de touches
** - LIST_ST: first item of the list
** - CUR_ITEM: current selected item on the list
*/
# define SEL_KEY_SIZE		7
# define KEY_NUMBER			22
# define ESC 				21
# define RET				5
# define CUR_X				conf->cur_pos[0]
# define CUR_Y				conf->cur_pos[1]
# define WIN_X				conf->w.ws_col
# define WIN_Y				conf->w.ws_row
# define LONGEST			ftsel[0]
# define ROWS				ftsel[1]
# define LIST_LEN			ftsel[2]
# define TMP				ftsel[3]
# define Y_OFFSET			ftsel[4]

//************************
//
//A VOIR POUR LE REMPLISSAGE DES FONCTIONS. ON DEFINIT LA MACRO COMME CA PAR DE REMPLISSAGE MANUEL A FAIRE
/*#define COLOR_STR(color)                            \
    (RED       == color ? "red"    :                \
     (BLUE     == color ? "blue"   :                \
      (GREEN   == color ? "green"  :                \
       (YELLOW == color ? "yellow" : "unknown"))))   */

/*
** SEQUENCE DE CARACTERES RETOURNEE PAR LA PRESSION DE LA TOUCHE
** DEPEND DU SYSTEME SUR LEQUEL EST COMPILE LE PROGRAMME
** NEXTWD : navigation par mot, aller au prochain mot
** PREVWD : navigatino par mot, aller au mot precedent
** LNUP : bouger ligne par ligne, aller a la ligne du dessus
** LNDOWN : bouger ligne par ligne, aller a la ligne inferieur
** CLEARSCR_SEQ : effacer l'ecran
** CUTST_CUR : couper depuis le debut jusqu'au curseur (Ctrl-J)
** CUTCUR_END : coupe depuis le curseur jusqu'a la fin (Ctrl-K)
** CPYST_CUR : couper depuis le debut jusqu'au curseur (Ctrl-U)
** CPYCUR_END : coupe depuis le curseur jusqu'a la fin (Ctrl-I)
** CUTLINE : couper l'ensemble de la ligne (Ctrl-U)
** PASTE : coller le texte precedemment coupe (Ctrl-Y)
*/
# define LEFT_SEQ			"\033[D"
# define RIGHT_SEQ			"\033[C"
# define UP_SEQ				"\033[A"
# define DOWN_SEQ			"\033[B"
# define ESC_SEQ			"\033"
# define RET_SEQ			"\012"
# define BKSP_SEQ			"\177"
# define DEL_SEQ			"\033[3~"
# define HOME_SEQ			"\033OH"
# define END_SEQ			"\033OF"
# define PGUP_SEQ			"\033[5~"
# define PGDOWN_SEQ			"\033[6~"

# ifdef __APPLE__
#  define NEXTWD_SEQ		"\e[1;5C"
#  define PREVWD_SEQ		"\e[1;5D"
#  define LNUP_SEQ			"LOL"
#  define LNDOWN_SEQ		"LOL"
#  define CLEARSCR_SEQ		"\f\000\000\000\000\000"
#  define CUTST_CUR_SEQ		"\n\000\000\000\000\000"
#  define CUTCUR_END_SEQ	"\v\000\000\000\000\000"
#  define CPYST_CUR_SEQ		"\v\000\000\000\000\000"
#  define CPYCUR_END_SEQ	"\v\000\000\000\000\000"
#  define PASTE_SEQ			"\v\000\000\000\000\000"
# endif

# ifdef __linux__
#  define NEXTWD_SEQ		"\033[1;5C"
#  define PREVWD_SEQ		"\033[1;5D"
#  define LNUP_SEQ			"\033[1;5A"
#  define LNDOWN_SEQ		"\033[1;5B"
#  define CLEARSCR_SEQ		"\f\000\000\000\000\000"
#  define CUTST_CUR_SEQ		"\n\000\000\000\000\000"
#  define CUTCUR_END_SEQ	"\v\000\000\000\000\000"
#  define CPYST_CUR_SEQ		"\025\000\000\000\000\000"
#  define CPYCUR_END_SEQ	"\t\000\000\000\000\000"
#  define PASTE_SEQ			"\031\000\000\000\000\000"
# endif

/*
** MACRO PERMETTANT D'acceder a la structure contenant la gestion
** de la touche
*/
# define KEY_TAB(i)			conf->keyman[i]
# define KLEFT				conf->keyman[0]
# define KRIGHT				conf->keyman[1]
# define KUP				conf->keyman[2]
# define KDOWN				conf->keyman[3]
# define KEND				conf->keyman[4]
# define KRET				conf->keyman[5]
# define KDEL				conf->keyman[6]
# define KBKSP				conf->keyman[7]
# define KHOME				conf->keyman[8]
# define KPGUP				conf->keyman[9]
# define KPGDOWN			conf->keyman[10]
# define KNEXTWD			conf->keyman[11]
# define KPREVWD			conf->keyman[12]
# define KLNUP				conf->keyman[13]
# define KLNDOWN			conf->keyman[14]
# define KCLEARSCR			conf->keyman[15]
# define KCUTST_CUR			conf->keyman[16]
# define KCUTCUR_END		conf->keyman[17]
# define KCPYST_CUR			conf->keyman[18]
# define KCPYCUR_END		conf->keyman[19]
# define KPASTE				conf->keyman[20]
# define KESC				conf->keyman[ESC]

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
int					terminal_input_mode(t_tconf *conf);
int					terminal_execute_mode(t_tconf *conf);
void				set_str_cap(char *cap_str);

/*
** KEY MANAGERS
*/
int					read_key(t_var *var);
int					return_command(t_var *var);
int					restore_terminal(t_var *var);
int					move_to_next_char(t_var *var);
int					move_to_previous_char(t_var *var);
int					move_to_next_char1(t_var *var);
int					move_to_previous_char1(t_var *var);
int					move_to_next_line(t_var *var);
int					move_to_next_word(t_var *var);
int					move_to_previous_word(t_var *var);
int					move_to_up_line(t_var *var);
int					move_to_origin(t_var *var);
int					move_to_end(t_var *var);
int					move_to_down_line(t_var *var);
int					insert_char(t_var *var);
int					delete_char(t_var *var);
int					erase_char(t_var *var);
int					cl_screen(t_var *var);
int					copy_from_start(t_var *var);
int					copy_from_end(t_var *var);
int					cut_from_start(t_var *var);
int					cut_from_end(t_var *var);
int					paste(t_var *var);

/*
** PRINTING
*/
void				ft_putstr_cursor_wrap(t_var *var);
void				ft_putchar_cursor(char c);
void				ft_putstr_cursor(char *str);
void				ft_putchar_fixed(char c);
void				ft_putstr_fixed(char *str);

/*
** TOOLS
*/
int					putchar_int(int c);
void				ft_putchar_cursor(char c);
void				ft_putstr_cursor(char *str);
void 				move_to(int x, int y);
void				update_win_size(int signo);
void				print_term_status(t_var *var);
void				print_term_set_cap(char *str);

#endif

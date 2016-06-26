/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:33:47 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 14:43:56 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H

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

typedef struct s_tconf		t_tconf;
typedef struct s_item		t_item;
typedef struct s_key_man	t_key_man;

/*
** seq_len is used in ft_strncmp to know the length of the keysequence to check
** key sequence to identify
** function to execute when the corresponding key is pressed
*/

struct	s_key_man
{
	size_t					seq_len;
	char					seq[SEL_KEY_SIZE];
	int						(*f)(t_tconf *, char *);
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

struct	s_tconf
{
	int						run;
	t_dlist					*list;
	t_dlist					*cur_item;
	int						row;
	int						col;
	int						fd;
	struct winsize			w;
	struct termios			def;
	struct termios			cur;
	char					term_buffer[2048];
	t_key_man				keyman[KEY_NUMBER];
};

/*
**	s: value of the selection
**	x: column position
**	y: row position
**	sel: item is selected
*/

struct	s_item
{
	size_t					len;
	int						x;
	int						y;
	char					*s;
	short					sel;
};

#endif

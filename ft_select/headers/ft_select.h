/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:33:47 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 14:43:56 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <ft_struct.h>

/*
**	TERMCAPS CAPS List
** ===========================
** Enter fullscreen mode : ti: <Esc> 7 <Esc> [ ? 47 h
** Exit fullscreen mode :  te: <Esc> [ 2 J <Esc> [ ? 4 7 l <Esc> 8
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

/*
** MAIN
*/
int					init_fd(int fd);
int					init_terminal(t_tconf *conf);
t_tconf				*get_instance();
void				print_small_size_error(t_tconf *conf);
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
int					load_term_prop(t_tconf *conf);
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
void				move_to(int x, int y);

/*
** DEBUG
*/
void				deb_item(t_item *item);

#endif

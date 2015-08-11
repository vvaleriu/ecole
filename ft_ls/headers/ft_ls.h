/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:08:17 by vincent           #+#    #+#             */
/*   Updated: 2015/08/11 17:22:17 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LS_H__
# define __FT_LS_H__
# define __LINUX__
# define _DARWIN_FEATURE_64_BIT_INODE

# define ERR_DIS	ft_putendl(strerror(errno))
# define LEN		ft_strlen
# define CMP		ft_strcmp
# define TVSEC		st_mtimespec.tv_sec
# define CT			content
# define DT			ft_difftime

# include <libft.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdio.h>
# include <sys/stat.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/xattr.h>

/*
** ARG_NB: maximum number of arguments option managed by ft_ls
** PRINT_PROP_NB: number of prop
** SHOW/HIDE TITLE: when multiple arg ls or recursive, title of the dir
**  has to be displayed or not. (used in ls_file)
*/

# define OPTIONS_NB			5
# define PRINT_PROP_NB		9

# define SHOW_TITLE			1
# define HIDE_TITLE			0
# define FIRST_TIME			1

typedef struct stat			t_stat;
typedef struct dirent		t_dirent;
typedef struct group		t_group;
typedef struct passwd		t_passwd;
typedef struct timespec		t_timespec;
typedef struct s_lsprop		t_lsprop;


# ifdef __LINUX__
//#  ifndef st_mtimespec
//#  define st_mtimespec		st_mtime
#  define t_timespec			time_t
//st_mtime st_mtimespec.tv_sec
//#  endif
# endif

/*
**	ERRORS
*/
# define ERR_ILL_OPT		"ft_ls: illegal option\n usage: ls [-lartR] [File ...]"

# define VAL_OPT_A			0
# define VAL_OPT_L			1
# define VAL_OPT_R			2
# define VAL_OPT_RC			3
# define VAL_OPT_T			4

# define OPT_A				prop->opt[VAL_OPT_A]
# define OPT_L				prop->opt[VAL_OPT_L]
# define OPT_R				prop->opt[VAL_OPT_R]
# define OPT_RC				prop->opt[VAL_OPT_RC]
# define OPT_T				prop->opt[VAL_OPT_T]

typedef struct		s_file
{
	char		*name;
	char		*fullpath;
	char		type;
	char		rights[9];
	char		xattr;
	char		*link_nb;
	char		user[8];
	char		group[8];
	char		*size;
	char		*mod;
	char		*min;
	char		*man;
	char		*lk;
	int			blk;
	time_t		*td;
}					t_file;

# define USR_L				pp[0]
# define LK_L				pp[1]
# define GRP_L				pp[2]
# define SIZE_L				pp[3]
# define MOD_L				pp[4]
# define MIN_L				pp[5]
# define MAN_L				pp[6]
# define CB_L				pp[7]
# define BLK_L				pp[8]

/*
** opt: array of short where each case is a activated/desactivated option
** pp: print
** il: initial_list
*/

struct s_lsprop
{
	short		opt[OPTIONS_NB];
	short		pp[PRINT_PROP_NB];
	t_list		*il;
	short		first_time;
	int			total;
};

/*
**	MAIN
*/

void		ls_file(t_lsprop *prop, t_list **il, int print_title);

/*
**	INIT
*/

int			init(t_lsprop *prop, int ac, char **av);
int			ft_set_options(t_lsprop *prop, int ac, char **av);

/*
**	TOOLS
*/
int			set_options(t_lsprop *prop, int ac, char **av);
int			ft_count_files(int ac, char **av);
void 		del_t_file_list(void *content, size_t size);
char		*get_file_path_name(char *directory, char *filename);
short		is_curr_prev_folder(t_file *file);

/*
**	PRINTING
*/
void		print_elem(t_lsprop *prop, t_file *file);
void		set_print_prop(t_file *file, short *pp);
void		reset_print_prop(short *pp);

/*
**	LIST
*/
t_list		*create_filenames_list(int ac, char **av);
t_list		*create_initial_list(t_lsprop *prop, t_list **fnames);
t_file		*get_file_info(t_lsprop *prop, char *filename);
t_list		*get_file_in_dir_info(t_lsprop *prop, char *dirname);

/*
**	PROPERTIES FINDERS
*/
char		ft_get_file_type(mode_t st_mode);
void		ft_get_file_rights(char *file_rights, mode_t st_mode);
//char		ft_get_file_xattr(mode_t file);
char		ft_get_file_xattr(char *file);
char		*ft_get_link_nb(nlink_t st_nlink);
char		*ft_get_user_name(uid_t st_uid);
char		*ft_get_group_name(gid_t st_gid);
char		*ft_get_file_size(off_t st_size);
char		*ft_get_last_mod(t_timespec st_mtspec);
//char		*ft_get_last_mod(time_t st_mtspec);
char		*ft_get_file_min(dev_t st_rdev);
char		*ft_get_file_man(dev_t st_rdev);

long int	ft_difftime(time_t time1, time_t time2);
char		*ft_readlink(char *path);
void		ft_sort(t_list **alst);
void		ft_sort_alpha_inv(t_list **alst);
void		ft_sort_date(t_list **alst);

/*void		ft_display_cont(t_list *alst, t_options opt, t_print_prop p);
void		ft_disp_link_nb(char *link_nb, int lk_l);
void		ft_disp_user(char *user, int usr_l);
void		ft_disp_group(char *group, int grp_l);
void		ft_disp_min(char *min, int min_l);
void		ft_disp_man(char *man, int man_l);
void		ft_disp_mod(char *mod, int mod_l);
void		ft_disp_size(char *size, t_print_prop pt);
void		ft_disp_link_name(char *lk, char *filetype);*/

#endif

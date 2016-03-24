/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:38:27 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/24 09:39:56 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <unistd.h>

# define FT_PI			3.141592653589793
# define FT_RAD			0.0174532925
# define I				t[0]
# define J				t[1]
# define K				t[2]
# define L				t[3]
# define GNL_BUFFER		1024

/*
**	PRINTF : FLAGS POSITION
**	CONVERSION QUALIFIER DEFINE
*/

# define FLAGSNUM		5

# define PF_ALT_PRINT	0
# define PF_AL_LEFT		1
# define PF_FILL_0		2
# define PF_SHOW_SIGN	3
# define PF_NEG_SIGN	4

# define PF_WIDTH		5
# define PF_ACC			6
# define PF_CONV_QUAL	7

# define PF_NUM_OF_FCT	14

# define PF_H_CQ		1
# define PF_HH_CQ		2
# define PF_L_CQ		3
# define PF_LL_CQ		4
# define PF_J_CQ		5
# define PF_Z_CQ		6

/*
**	PRINTF : FLAGS POSITION
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct		s_pf_flag
{
	char	fl;
	int		val;
}					t_pf_flag;

typedef struct		s_pf_print_func
{
	char	id;
	int		(*f)(void *pt, t_pf_flag *flags);
}					t_pf_print_func;

/*
**		_____GET_NEXT_LINE STRUCTURE
*/

typedef	struct		s_str_prop
{
	int		rd;
	char	*file;
	char	*tmp;
	char	*buf;
	char	*end;
}					t_str_prop;

/*
**		LIBFT STANDARD
*/

void				*ft_memmove(void *dst, const void *src, size_t n);
int					ft_putchar(char c);
int					ft_putstr(const char *s);
void				ft_putnbr(int n);
int					ft_putnbr_unsign(unsigned int n);
int					ft_putendl(char const *s);
void				ft_strclr(char *s);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *dest, const char *src);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
void				ft_putstr_array(char **array);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memdup(const void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *str, char c);
char				*ft_itoa(int n);
char				*ft_itoa_unsign(unsigned int n);
char				*ft_itoa_long(long int n);
char				*ft_itoa_unsign_long(unsigned long int n);
char				*ft_ftoa(float n);
unsigned int		ft_itoo(unsigned int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strrev(char *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstsplit(t_list *alst, t_list *elem);
t_list				*ft_elemdup(t_list *elem);

/*
**	t_dlist functions
*/
void				ft_dlstadd_last(t_dlist **alst, t_dlist *new);
void				ft_dlstadd(t_dlist **alst, t_dlist *new);
int					ft_dlstlen(t_dlist *alst);
t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
void				ft_dlstdelone(t_dlist **alst, t_dlist *d, void (*del)(void *, size_t));

int					ft_lstlen(t_list *list);
void				ft_lstadd_last(t_list **alst, t_list *new);
char				*ft_itoh(unsigned int n);
char				*ft_itoa_char(char n);
char				*ft_itoh_cap(unsigned int n);
char				*ft_itoh_long(long unsigned int n);
char				*ft_itoh_long_cap(long unsigned int n);
char				*ft_otoa(unsigned int n);
char				*ft_otoa_char(unsigned char n);
char				*ft_otoa_short(unsigned short int n);
char				*ft_otoa_long(unsigned long int n);
int					ft_fill_print(int n, char c);
int					ft_isspace(char c);
double				ft_pitorad(double ang);
double				ft_atod(char *s);
int					ft_putwchar(wchar_t wc);
int					ft_putwstr(wchar_t const *s);
wchar_t				*ft_wstrndup(const wchar_t *s1, size_t n);
size_t				ft_wstrlen(const wchar_t *s);
wchar_t				*ft_wstrdup(const wchar_t *s1);
void				*ft_wstrdel(wchar_t **s1);
char				*ft_itoa_short(short int n);
char				*ft_itoa_unsign_short(unsigned short int n);
int					get_next_line(int const fd, char **line);
int					is_space(char c);
int					is_operator(char c);
int					is_text(char c);
int					is_quote(char c);
void				ft_strarray_del(char ***c);
void				ft_strarray_del_one(char ***c, int pos);
int	    			ft_strarray_len(char **ar);
int 				ft_strarray_char_len(char **ar);
void				ft_strarray_add_first(char ***ar, char *str);
void				ft_strarray_add_last(char ***ar, char *str);

/*
**		ERROR CHECKER
*/

int					err_int(int err, int res, char *str, int quit);
void				*err_void(void *err, void *res, char *str, int quit);

/*
**		============================
**		========== PRINTF ==========
**		============================
*/

/*
**		Init & reset functions
*/

void				pf_init_func_array(t_pf_print_func *func);
void				pf_init_all_arrays(t_pf_flag *flags);

/*
**		Flags & options setup
*/

int					pf_set_flags(t_pf_flag *flags, char **s);
void				pf_set_width(t_pf_flag *flags, char **s, va_list ap);
void				pf_set_accuracy(t_pf_flag *flags, char **s, va_list ap);
void				pf_set_conv_qual(t_pf_flag *flags, char **s);
void				pf_reset_options(t_pf_flag *flags);
void				pf_options_setup(t_pf_flag *flags, char **s, va_list ap);

/*
**		Conversions
*/

int					ft_printf(const char *s1, ...);
int					pf_print_d(int n, t_pf_flag *flags);
int					pf_print_d_long(long int n, t_pf_flag *fl);
int					pf_print_d_h(int n, t_pf_flag *fl);
int					pf_print_d_hh(int n, t_pf_flag *fl);
int					pf_print_d_j(long int n, t_pf_flag *fl);
int					pf_print_c(int n, t_pf_flag *flags);
int					pf_print_c_cap(wchar_t v, t_pf_flag *fl);
int					pf_print_s(char *s, t_pf_flag *flags);
int					pf_print_s_cap(wchar_t *s, t_pf_flag *flags);
int					pf_print_o(unsigned int n, t_pf_flag *flags);
int					pf_print_o_h(unsigned short int n, t_pf_flag *fl);
int					pf_print_o_hh(unsigned char n, t_pf_flag *fl);
int					pf_print_o_long(unsigned long int n, t_pf_flag *flags);
int					pf_print_x(unsigned int n, t_pf_flag *flags);
int					pf_print_x_h(unsigned int n, t_pf_flag *fl);
int					pf_print_x_hh(unsigned int n, t_pf_flag *fl);
int					pf_print_x_long(unsigned long int n, t_pf_flag *fl);
int					pf_print_x_cap(unsigned int n, t_pf_flag *flags);
int					pf_print_x_cap_h(unsigned int n, t_pf_flag *fl);
int					pf_print_x_cap_hh(unsigned int n, t_pf_flag *fl);
int					pf_print_x_cap_long(unsigned long int n, t_pf_flag *fl);
int					pf_print_f(double n, t_pf_flag *flags);
int					pf_print_p(void *prt, t_pf_flag *flags);
int					pf_print_u(unsigned int n, t_pf_flag *flags);
int					pf_print_u_long(unsigned long int n, t_pf_flag *flags);
int					pf_print_u_h(unsigned int n, t_pf_flag *flags);
int					pf_print_u_hh(unsigned int n, t_pf_flag *flags);
int					pf_print_pos(char *s, t_pf_flag *flags);
int					pf_print_neg(char *s, t_pf_flag *flags);
int					pf_print_purcentage(t_pf_flag *fl);
int					pf_print_spaces(t_pf_flag *fl, char **t);

/*
**		Tools
*/

int					pf_repeat_char(char c, int i);
int					pf_print_d_before(t_pf_flag *fl, int n, size_t len);
int					pf_print_d_after(t_pf_flag *fl, size_t len);
int					pf_print_d_long_before(t_pf_flag *fl, long int n, size_t l);
int					pf_print_d_long_after(t_pf_flag *fl, size_t len);
int					pf_print_o_before(t_pf_flag *fl, size_t len);
int					pf_print_o_after(t_pf_flag *fl, size_t len);
int					pf_print_s_before(t_pf_flag *fl, size_t len);
int					pf_print_s_after(t_pf_flag *fl, size_t len);
int					pf_print_u_before(t_pf_flag *fl, size_t le, char *s);
int					pf_print_u_after(t_pf_flag *fl, size_t len);
int					pf_print_x_before(t_pf_flag *fl, size_t l, unsigned int n);
int					pf_print_x_after(t_pf_flag *fl, int j);
int					pf_print_x_cap_before(t_pf_flag *fl, size_t l, unsigned n);
void				pf_check_s(int *i, t_pf_flag *fl, va_list ap, char **t);
void				pf_check_u(int *i, t_pf_flag *fl, va_list ap, char **t);
void				pf_check_d(int *i, t_pf_flag *fl, va_list ap, char **t);
void				pf_check_c(int *i, t_pf_flag *fl, va_list ap, char **t);
void				pf_check_x(int *i, t_pf_flag *fl, va_list ap);
void				pf_check_x_cap(int *i, t_pf_flag *fl, va_list ap);
void				pf_check_o(int *i, t_pf_flag *fl, va_list ap, char **t);

#endif

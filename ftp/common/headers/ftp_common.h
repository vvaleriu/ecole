#ifndef COMMON_H
# define COMMON_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**	SK_SERV, SK_CLIENT : Types contained in t_fd structure
**	SV_SOCK: macro to access server socket (= files descriptor) value
**	CL_SOCK(i): macro to access a client socket (= files descriptor) value
*/

# define ERR_USAGE			"usage"

# define SK_SERV			0
# define SK_CLIENT			1
# define SK_FREE			2

/*
**		!!!!! type of data that are gonna be transmit !!!!!
**	T_COMMAND 	: send a command to the server or the client
**	T_BINARY	: file to be exchanged
**	T_OUTPUT	: message te be printed on stdout
*/

# define T_COMMAND			0;
# define T_BINARY			1;
# define T_OUTPUT			2;

/*
**	BUF_SIZE: size of the buffer for read and write operation for each socket
**	NAME_SIZE: size of the array reserved for the name in t_send_info structure
*/

# define BUF_SIZE			4096
# define NAME_SIZE			512

/*	
**	ERROR FUNCTIONS
**	Used in error checking functions
**	Tells the function wether an error has to exit or continue running the exe.
*/

# define E(e, r, s, q)		err_int(e, r, s, q)
# define EV(e, r, s, q)		err_void(e, r, s, q)
# define NO_EXIT			0
# define FORCE_EXIT			1

typedef struct s_fd			t_fd;
typedef struct s_send_info	t_send_info;

/*
**	sd: 		socket descriptor
**	type		SK_FREE	0, SK_SERV	1, SK_CLIENT	2
**	ft_read:	pointer on read function
**	ft_write:	pointer on write function
*/

struct			s_fd
{
	void	(*ft_read)();
	void	(*ft_write)();
	int		sock;
	int		type;
	char	rd[BUF_SIZE + 1];
	char	wr[BUF_SIZE + 1];
};

/*
**				structure PAKET INFO
**	first bit being send to inform the receiver about what it will receive
**	type		0 message, 1  binary. cf above defines. let the receiver chose the correct
**				treatment after reception
*/

struct			s_send_info
{
	short		type;
	off_t		size;
	char		fname[NAME_SIZE];
};


/*
** 			LEXING FUNCTIONS
*/

char						**lexer(char *buf);
void						lex_space(char **buf);
void						lex_char(char **buf, t_list **alst);
char						**list_to_tab(t_list *l);

/*
** 			NETWORK FUNCTIONS
*/

int							nt_send_info(int socket, t_send_info *info);
int							nt_receive_info(int socket, t_send_info *info);
void						nt_display_send_info(t_send_info info);

/*
**				ERROR MANAGEMENT
*/

void						usage(int target, int ac, char **av);
void						pterr(char *err);
int							err_int(int err, int res, char *str, int quit);
void						*err_void(void *err, void *res, char *str, int quit);

/*
**				SIGNAL MANAGEMENT
*/

void						sig_handler(int signo);

#endif
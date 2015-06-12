#ifndef SERVER_H
# define SERVER_H

# include <libft.h>
# include <ftp_server_error.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <ftp_server.h>
# include <netinet/in.h>
# include <sys/socket.h>

/*
**	SK_SERV, SK_CLIENT : Types contained in t_fd structure
**	SV_SOCK: macro to access server socket (= files descriptor) value
**	CL_SOCK(i): macro to access a client socket (= files descriptor) value
*/
	
# define SK_SERV			0
# define SK_CLIENT			1
# define SK_FREE			2
	
# define SV_SOCK			sv->fds[0].sock
# define CL_SOCK(i)			sv->fds[i].sock
	
/*	
**	ERROR FUNCTIONS
**	Used in error checking functions
**	Tells the function wether an error has to exit or continue running the exe.
*/	
	
# define E(e, r, s, q)		err_int(e, r, s, q)
# define EV(e, r, s, q)		err_void(e, r, s, q)
# define NO_EXIT			0
# define FORCE_EXIT			1

/*
**	BUF_SIZE: size of the buffer for read and write operation for each socket
**	QUEUE_LENGTH: maximum number of pending connection (used in listen())
**	MAX_SOCKETS: MAX_CLIENTS + server socket (1)
*/

# define BUF_SIZE			4096
# define QUEUE_LENGTH		10
# define BIN_NB				7
# define MAX_CLIENTS		10
# define MAX_SOCKETS		1 + MAX_CLIENTS

typedef struct s_cmd		t_cmd;
typedef struct s_cl_prop	t_cl_prop;
typedef struct s_fd			t_fd;
typedef struct s_sv_prop	t_sv_prop;

/*
**	root_dir	dir of the binary, can't go upper than that (STACK)
**	env:		environment variables (STACK)
**	path:		list of dir in which to look for the exe (init at start) (HEAP)
**	bin:		list of string of allowed command on the server (init at start) (HEAP)
**	cmda:		list of string, cmda[0]: exe name, cmda[1]: args, etc. (HEAP)
**	cmd:		client entered command (HEAP)
*/

struct			s_cmd
{
	char				*root_dir;
	char				**env;
	char				**path;
	char				**bin;
	char				**cmda;
	char				*cmd;
};

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
	char	read_b[BUF_SIZE + 1];
	char	write_b[BUF_SIZE + 1];
};
	
/*
**	fds:	array of socks, 0: is "master server socket",
**			the rest are clients
**	port:	port
**	fd: 	server fd
**	max:	value of the higher file descriptor
**	left:	number of file despcriptor left after select called (= file descrip
**			in which there is something to read/write)
**	readfds: set of read file descriptor
**	writefds: set of write fds
*/

struct			s_sv_prop
{
	t_cmd				*cmd;
	t_fd				*fds;
	fd_set				readfds;
	fd_set				writefds;
	int					max;
	int					left;
	unsigned short		port;
};

/*
**				SERVER LOGIC
*/

int							sv_launch(t_sv_prop *prop);
int							sv_create(t_sv_prop *prop);
void						sv_accept(t_sv_prop *sv);
void						sv_kill(t_sv_prop *sv);
void						clean_fd(t_fd *fd);
void						init_fds(t_sv_prop *sv);
void						check_fds(t_sv_prop *sv);
void						select_fds(t_sv_prop *sv);
void						main_loop(t_sv_prop *sv);
void						sv_new_cl_info(struct sockaddr_in csin, int i);
void						sv_socket_state(t_sv_prop *sv, char *tag);
void						kill_sockets(t_sv_prop *sv);

/*
**			EXECUTION FUNCTIONS
*/

char						*get_path(t_sv_prop *sv);
int							exe_command(t_sv_prop *sv);
int							check_command(t_sv_prop *sv);
void						ft_read(t_sv_prop *sv, int i);
void						ft_write(t_sv_prop *sv, int i);

/*
** 			LEXING FUNCTIONS
*/

char						**lexer(char *buf);
void						lex_space(char **buf);
void						lex_char(char **buf, t_list **alst);
char						**list_to_tab(t_list *l);

/*
**				INPUT LISTENER
*/

void						read_client_input(t_sv_prop *sv);
void						kill_server(t_sv_prop *sv);
/*
**				ERROR MANAGEMENT
*/

void						usage(int ac, char **av);
void						pterr(char *err);
int							err_int(int err, int res, char *str, int quit);
void						*err_void(void *err, void *res, char *str, int quit);

/*
**				INITIALISATION
*/

void						init_sv_prop(t_sv_prop *sv, char *port, char **env);
void						init_env(t_sv_prop *sv, char **env);
void						init_command_list(t_sv_prop *sv);

/*
**				TOOLS
*/

void						sv_status(char *status);
int							max(int a, int b);
void						sig_handler(int signo);

#endif
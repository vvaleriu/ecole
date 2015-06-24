#ifndef SERVER_H
# define SERVER_H

# include <libft.h>
# include <ftp_common.h>
# include <ftp_server_error.h>
# include <unistd.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/types.h>
#include <stdio.h>

/*
**	CL_SOCK(i): macro to access a client socket (= files descriptor) value
*/

# define SV_SOCK			sv->fds[0].sock
# define CL_SOCK(i)			sv->fds[i].sock

/*
**	BUF_SIZE: size of the buffer for read and write operation for each socket
**	QUEUE_LENGTH: maximum number of pending connection (used in listen())
**	MAX_SOCKETS: MAX_CLIENTS + server socket (1)
*/

# define BUF_CWD			1024
# define QUEUE_LENGTH		10
# define BIN_NB				6
# define MAX_CLIENTS		10
# define MAX_SOCKETS		1 + MAX_CLIENTS

typedef struct s_cmd		t_cmd;
typedef struct s_sv_prop	t_sv_prop;
typedef struct s_bin 		t_bin;

/*
**	name	name of the command
**	f		function associated with the command
*/

struct			s_bin
{
	char		*name;
	int			(*f)();
};

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
	t_bin				*bin;
	char				*root_dir;
	char				**env;
	char				**path;
	char				**cmda;
	char				*cmd;
	char				*gnl;
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
int							sv_kill(t_sv_prop *sv);
void						init_fds(t_sv_prop *sv);
void						check_fds(t_sv_prop *sv);
void						select_fds(t_sv_prop *sv);
void						main_loop(t_sv_prop *sv);
void						sv_new_cl_info(struct sockaddr_in csin, int i);
void						sv_socket_state(t_sv_prop *sv, char *tag);
void						kill_sockets(t_sv_prop *sv);
void						kill_cmd(t_sv_prop *sv);
void 						exit_announce(t_sv_prop *sv);

/*
**			EXECUTION FUNCTIONS
*/

char						*get_path(t_sv_prop *sv);
int							exe_command(t_sv_prop *sv, int i);
int							execute(t_sv_prop *sv, int i);
void						ft_read(t_sv_prop *sv, int i);
void						ft_write(t_sv_prop *sv, int i);
void						execute_sv(t_sv_prop *sv);

/*
** 			SEND / RECEIVE FUNCTIONS
*/

void						sv_receive_command(t_sv_prop *sv, int cl);
void						sv_receive_prepare(t_sv_prop *sv, int cl);
void						sv_send_prepare(t_sv_prop *sv, int cl);

/*
** 			BUILT IN FUNCTIONS
*/

int							bin_cd(t_sv_prop *sv, int i);
int							bin_help(t_sv_prop *sv, int i);
int							bin_pwd(t_sv_prop *sv, int i);
int							bin_get(t_sv_prop *sv, int i);
int							send_file_info(t_sv_prop *sv, char *fname, int file_fd, int cl);
int							err_no_file(t_sv_prop *sv, int cl);
int							send_file(t_sv_prop *sv, char *filename, int i);

/*
**				INPUT LISTENER
*/

void						read_client_input(t_sv_prop *sv);
void						kill_server(t_sv_prop *sv);

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
void						sv_prop(t_sv_prop *sv);

#endif
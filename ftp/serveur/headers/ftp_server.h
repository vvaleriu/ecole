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

# define BUF_SIZE		4096
# define QUEUE_LENGTH	42
# define BIN_NB			7


typedef struct s_cmd		t_cmd;
typedef struct s_cl_prop	t_cl_prop;
typedef struct s_fd			t_fd;
typedef struct s_sv_prop	t_sv_prop;

/*
**	CLIENT PROP STRUCTURE
**
**	sock: 		server socket
**	sin:		socket address
**	slen:		socket length
*/

struct			s_cl_prop
{
	int					sock;
	struct sockaddr_in	sin;
	unsigned int		slen;
};					

struct			s_cmd
{
	char				*root_dir;
	char				**env;
	char				**path;
	char				**bin;
	char				**cmda;
	char				*cmd;
};

typedef struct	s_fd
{
	int		type;
	void	(*ft_read)();
	void	(*ft_write)();
	char	buf_read[BUF_SIZE + 1];
	char	buf_write[BUF_SIZE + 1];
};
		
/*
**	root_dir	dir of the binary, can't go upper than that
**	env:		environment variables
**	path:		list of dir to look for the exe
**	bin:		list of string of allowed command on the server
**	cmda:		list of string, cmda[0]: exe name, cmda[1]: args, etc.
**	cmd:		client entered command
**	port:		port
**	sock: 		server socket
**	cs:			client socket
**	csin:
*/
		
typedef struct			s_sv_prop
{
	t_fd				*fds;
	t_cmd				*cmd;
	t_cl_prop			cl;
	unsigned short		port;
	int					sock;
	int					maxfd;
	int					max;
	int					r;
	fd_set				fd_read;
	fd_set				fd_write;
};

/*
**				SERVER LOGIC
*/

int							sv_launch(t_sv_prop *prop);
int							sv_create(t_sv_prop *prop);
void						kill_server(t_sv_prop *sv);

/*
**			EXECUTION FUNCTIONS
*/

char						*get_path(t_sv_prop *sv);
int							exe_command(t_sv_prop *sv);
int							check_command(t_sv_prop *sv);

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

void						usage(char *binname, char *error);
void						pterr(char *err);


/*
**				INITIALISATION
*/

void						init_sv_prop(t_sv_prop *sv, char *port, char **env);
void						init_command_list(t_sv_prop *sv);

#endif
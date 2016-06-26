#ifndef COMMON_H
# define COMMON_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <sys/mman.h>

/*
**				ERRORS
*/

# define ERR_RECV				"Error with received data. Recv function error."
# define ERR_WRITE_FILE			"Could not write to this file descriptor"
# define ERR_FILE_NOT_FOUND		"File not found on the client. Check file path and name."
# define ERR_INVALID_PORT		"This is not a valid port."
# define ERR_INVALID_PORT_RANGE	"A valid port value must be between 0 and 65535"
# define ERR_EMPTY_ENV			"env not found."


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

# define T_COMMAND			0
# define T_BINARY			1
# define T_OUTPUT			2

/*
** COMMAND VALUES
*/

# define CMD_LS				0
# define CMD_CD				1
# define CMD_GET			2
# define CMD_PWD			3
# define CMD_HELP			4
# define CMD_QUIT			5

/*
**	BUF_SIZE: size of the buffer for read and write operation for each socket
**	NAME_SIZE: size of the array reserved for the name in t_send_info structure
*/

# define BUF_SIZE			4096
# define NAME_SIZE			512

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
**				structure PAKET INFO
**	first bit being send to inform the receiver about what it will receive
**	type		0 message, 1  binary. cf above defines. let the receiver chose the correct
**				treatment after reception
*/

struct			s_send_info
{
	off_t		size;
	char		fname[NAME_SIZE];
	int			type;
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

int							nt_send_info(int sock, int type, off_t size, char *name);
int							nt_receive_info(int socket, t_send_info *info);
int							nt_display_send_info(t_send_info info);
int							nt_receive_files(int sock, char *buf, t_send_info *info);
int							nt_send_files(char **files, int sock);

/*
** 			TOOLS FUNCTIONS
*/

void						clean_fd(t_fd *fd);
void						wipe_fd(t_fd *fd);
void						check_port(char *port);

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
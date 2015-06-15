#ifndef CLIENT_H
# define CLIENT_H

# include <libft.h>
# include <ftp_common.h>
# include <ftp_client_error.h>
# include <unistd.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <sys/socket.h>

# define SOCK			cl->fd.sock

typedef struct			s_cl_prop
{
	t_fd				fd;
	fd_set				readfds;
	fd_set				writefds;
	int					max;
	unsigned short		port;
	char				*ip;

}						t_cl_prop;

/*
**				CLIENT LOGIC
*/

int							cl_connect(t_cl_prop *prop);
void						cl_kill(t_cl_prop *cl, char **cmd);
void						check_fds(t_cl_prop *cl);
void						init_fds(t_cl_prop *cl);
void						cl_select(t_cl_prop *cl);
int							main_loop(t_cl_prop *cl);
void						init_fds(t_cl_prop *cl);
int							cmd_input(t_cl_prop * cl);

/*
**				CLIENT SEND
*/

void						cl_send(t_cl_prop * cl);

/*
**				CLIENT RECEIVE
*/

void						cl_receive(t_cl_prop *cl);

/*
**				INITIALISATION
*/

void						init_cl_prop(t_cl_prop *cl, char *ip, char *port);

#endif
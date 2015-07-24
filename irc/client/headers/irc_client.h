#ifndef CLIENT_H
# define CLIENT_H

# include <libft.h>
# include <irc_common.h>
# include <irc_client_error.h>
# include <unistd.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <fcntl.h>

# define SOCK			cl->fd.sock

# define CL_BIN			3

typedef struct			s_cl_prop
{
	t_fd				fd;
	fd_set				readfds;
	fd_set				writefds;
	t_bin				bin[CL_BIN];
	char				**path;
	int					max;
	char				*gnl;
	char				*ip;
	unsigned short		port;
}						t_cl_prop;

/*
**				CLIENT LOGIC
*/

int							cl_connect(t_cl_prop *prop);
void						cl_kill(t_cl_prop *cl);
void						check_fds(t_cl_prop *cl);
void						init_fds(t_cl_prop *cl);
void						cl_select(t_cl_prop *cl);
int							main_loop(t_cl_prop *cl);
void						init_fds(t_cl_prop *cl);

/*
**				CLIENT SEND
*/

void						cl_send_prepare(t_cl_prop * cl);
void						cl_send_command(t_cl_prop *cl);
int							is_client_side_command(t_cl_prop *cl, char *s);
/*
**				CLIENT RECEIVE
*/

void						cl_receive_prepare(t_cl_prop *cl);
//int							cl_receive_output(t_cl_prop *cl, int sock, char *buf, t_send_info *info);
//int							cl_receive_output(t_cl_prop *cl, t_send_info *info);
int							cl_receive_output(t_cl_prop *cl);

/*
**				CLIENT SEND
*/


int							exe_command(t_cl_prop *cl, char **cmda);
char						*get_path(t_cl_prop *cl, char **cmda);
char						*ft_readdir(char *exe, char *rep);

/*
**				INITIALISATION
*/

void						init_cl_prop(t_cl_prop *cl, char *ip, char *port, char **env);
void						init_env(t_cl_prop *cl, char **env);
void						init_command_list(t_cl_prop *cl);

#endif
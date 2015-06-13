#ifndef CLIENT_H
# define CLIENT_H

# include <libft.h>
# include <ftp_common.h>
# include <ftp_client_error.h>
# include <unistd.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <sys/socket.h>

typedef struct			s_cl_prop
{
	t_fd				fd;
	unsigned short		port;
	char				*ip;
}						t_cl_prop;

/*
**				CLIENT LOGIC
*/

int							cl_connect(t_cl_prop *prop);
void						cl_kill(t_cl_prop *cl, char **cmd);

/*
**				CLIENT COMMAND
*/

int							cmd_input(t_cl_prop * cl);

/*
**				INITIALISATION
*/

void						init_cl_prop(t_cl_prop *cl, char *ip, char *port);

#endif
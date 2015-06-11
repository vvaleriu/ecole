#ifndef CLIENT_H
# define CLIENT_H

# include <libft.h>
# include <ftp_client_error.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#include <netinet/in.h>
#include <sys/socket.h>

typedef struct			s_cl_prop
{
	char				*ip;
	unsigned short		port;
	int					sock;
	int					cs;
}						t_cl_prop;

/*
**				CLIENT LOGIC
*/

int							cl_connect(t_cl_prop *prop);
void						cl_kill(t_cl_prop *cl, char *cmd);

/*
**				CLIENT COMMAND
*/

int							cmd_input(t_cl_prop * cl);

/*
**				ERROR MANAGEMENT
*/

void						usage(char *binname, char *error);
void						pterr(char *err);


/*
**				INITIALISATION
*/

void						init_cl_prop(t_cl_prop *cl, char *ip, char *port);

#endif
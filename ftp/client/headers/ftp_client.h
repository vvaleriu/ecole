#ifndef CLIENT_H
# define CLIENT_H

# include <libft.h>
# include <ftp_client_error.h>
# include <unistd.h>

#include <netinet/in.h>
#include <sys/socket.h>

# define QUEUE_LENGTH	42

typedef struct			s_svcl_prop
{
	char				*ip;
	unsigned short		port;
	int					sock;
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;
	struct protoent		*proto;
}						t_cl_prop;

/*
**				SERVER LOGIC
*/

int							create_client(t_cl_prop *prop);

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
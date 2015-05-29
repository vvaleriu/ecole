#ifndef SERVER_H
# define SERVER_H

# include <libft.h>
# include <ftp_server_error.h>
# include <unistd.h>

#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>

# define QUEUE_LENGTH	42

typedef struct			s_sv_prop
{
	unsigned short		port;
	int					sock;
	int					cs;
	struct sockaddr_in	csin;
	unsigned int		cslen;
	struct protoent		*proto;
}						t_sv_prop;

/*
**				SERVER LOGIC
*/

int							create_server(t_sv_prop *prop);

/*
**				ERROR MANAGEMENT
*/

void						usage(char *binname, char *error);
void						pterr(char *err);


/*
**				INITIALISATION
*/

void						init_sv_prop(t_sv_prop *sv, char *port);

#endif
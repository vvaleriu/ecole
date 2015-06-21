#include <ftp_server.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void		clean_fd(t_fd *fd)
{
	fd->type = SK_FREE;
	fd->sock = 0;
	fd->ft_read = NULL;
	fd->ft_write = NULL;
}
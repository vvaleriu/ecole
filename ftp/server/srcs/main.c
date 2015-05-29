#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>

int					main(int ac, char **av)
{
	t_sv_prop		sv;

	if (ac != 2)
	{
		usage(av[0], ERR_USAGE);
		return (0);
	}
	init_sv_prop(&sv, av[1]);
	create_server(&sv);
	sv.cs = accept(sv.sock, (struct sockaddr *)&(sv.csin), &(sv.cslen));
	close(sv.cs);
	close(sv.sock);
	return (0);
}

void				init_sv_prop(t_sv_prop *sv, char *port)
{
	sv->port = (unsigned short) ft_atoi(port);
	sv->sock = 0;
	sv->proto = NULL;
}
#include <ftp_client.h>
#include <netinet/in.h>
#include <sys/socket.h>

int					main(int ac, char **av)
{
	t_cl_prop		cl;

	if (ac != 3)
	{
		usage(av[0], ERR_USAGE);
		return (0);
	}
	init_cl_prop(&cl, av[1], av[2]);
	connect_client(&cl);
	//write(cl.sock, "ls -l\n", 11);
	input_command(&cl);
	//close(cl.sock);
	return (0);
}

void				init_cl_prop(t_cl_prop *cl, char *ip, char *port)
{
	cl->ip = ft_strdup(ip);
	ft_strdel(&(cl->ip));
	cl->ip = ft_strdup("127.0.0.1");
	cl->port = (unsigned short) ft_atoi(port);
	cl->sock = 0;
}
#include <ftp_client.h>
#include <netinet/in.h>
#include <sys/socket.h>

void				init_cl_prop(t_cl_prop *cl, char *ip, char *port, char **env)
{
	cl->max = 0;
	cl->gnl = NULL;
	cl->ip = ft_strdup(ip);
	check_port(port);
	cl->port = (unsigned short) ft_atoi(port);
	init_env(cl, env);
	init_command_list(cl);
	clean_fd(&(cl->fd));
	cl->fd.type = SK_CLIENT;
}

void				init_env(t_cl_prop *cl, char **env)
{
	int		i;

	i = 0;
	EV(NULL, env, ERR_EMPTY_ENV, FORCE_EXIT);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	EV(NULL, env[i], ERR_EMPTY_ENV, FORCE_EXIT);
		cl->path = ft_strsplit(env[i] + 5, ':');
}

void				init_command_list(t_cl_prop *cl)
{
	cl->bin[0].name = ft_strdup("cls");
	cl->bin[0].f = exe_command;
	cl->bin[1].name = ft_strdup("ccd");
	cl->bin[1].f = exe_command;
	cl->bin[2].name = ft_strdup("cpwd");
	cl->bin[2].f = exe_command;
}

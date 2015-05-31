#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>

int					main(int ac, char **av, char **env)
{
	t_sv_prop		sv;

	if (ac != 2)
	{
		usage(av[0], ERR_USAGE);
		return (0);
	}
	init_sv_prop(&sv, av[1], env);
	lauch_server(&sv);
	read_client_input(&sv);
	kill_server(&sv);
	return (0);
}

void				init_sv_prop(t_sv_prop *sv, char *port, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	sv->port = (unsigned short) ft_atoi(port);
	sv->sock = 0;
	sv->cmd = NULL;
	if (env != NULL)
	{
		sv->env = env;
		while (env[i] && ft_strncmp(env[i], "PATH=", 5))
			i++;
		if (env[i])
		{
			sv->path = ft_strsplit((tmp = ft_strdup(env[i] + 5)), ':');
			ft_strdel(&tmp);
		}
		else
		{
			pterr(ERR_EMPTY_ENV);
			exit(2);
		}
	}
	else
	{
		pterr(ERR_EMPTY_ENV);
		exit(2);
	}
}

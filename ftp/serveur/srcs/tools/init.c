#include <ftp_server.h>

/*
**
**
*/

void				init_sv_prop(t_sv_prop *sv, char *port, char **env)
{
	int				i;
	char			*tmp;
	struct rlimit	rlp;

	i = 0;
	sv->port = (unsigned short) ft_atoi(port);
	sv->sock = 0;
	sv->cmd = (t_cmd *)ft_memalloc(sizeof(t_cmd) * 1);
	getrlimit(RLIMIT_NOFILE, &rlp);
	sv->maxfd = rlp.rlim_cur;
	sv->s = (t_sock *)ft_memalloc(sizeof(t_sock) * sv->maxfd + 1);
	while (i++ < sv->maxfd)
		clean_socket(sv-s[i])
	init_env(sv, env);
	init_command_list(sv);
}

void				init_env(t_sv_prop *sv, char **env)
{
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

void				init_command_list(t_sv_prop *sv)
{
	sv->bin = (char **)ft_memalloc(sizeof(char *) * BIN_NB + 1);
	sv->bin[0] = ft_strdup("ls");
	sv->bin[1] = ft_strdup("cd");
	sv->bin[2] = ft_strdup("get");
	sv->bin[3] = ft_strdup("put");
	sv->bin[4] = ft_strdup("pwd");
	sv->bin[5] = ft_strdup("help");
	sv->bin[6] = ft_strdup("quit");
}
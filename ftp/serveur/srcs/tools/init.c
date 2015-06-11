#include <ftp_server.h>

/*
**
**
*/

void				init_sv_prop(t_sv_prop *sv, char *port, char **env)
{
	int				i;

	i = 0;
	sv->max = 0;
	printf("init_sv_prop - Adresse de sv: %p\n", sv);
	sv->port = (unsigned short) ft_atoi(port);
	sv->cmd = (t_cmd *)ft_memalloc(sizeof(*(sv->cmd)));
	sv->fds = (t_fd *)ft_memalloc(sizeof(*(sv->fds)) * MAX_SOCKETS);
	while (i < MAX_SOCKETS)
		clean_fd(&(sv->fds[i++]));
	init_env(sv, env);
	init_command_list(sv);
}

void				init_env(t_sv_prop *sv, char **env)
{
	int		i;

	i = 0;
	EV(NULL, env, ERR_EMPTY_ENV, FORCE_EXIT);
	sv->cmd->env = env;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	EV(NULL, env[i], ERR_EMPTY_ENV, FORCE_EXIT);
		sv->cmd->path = ft_strsplit(env[i] + 5, ':');
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PWD=", 4))
		i++;
	EV(NULL, env[i], ERR_EMPTY_ENV, FORCE_EXIT);
	sv->cmd->root_dir = env[i] + 4;
}

void				init_command_list(t_sv_prop *sv)
{
	sv->cmd->bin = (char **)ft_memalloc(sizeof(char *) * BIN_NB + 1);
	sv->cmd->bin[0] = ft_strdup("ls");
	sv->cmd->bin[1] = ft_strdup("cd");
	sv->cmd->bin[2] = ft_strdup("get");
	sv->cmd->bin[3] = ft_strdup("put");
	sv->cmd->bin[4] = ft_strdup("pwd");
	sv->cmd->bin[5] = ft_strdup("help");
	sv->cmd->bin[6] = ft_strdup("quit");
}

/*
void				init_env(t_sv_prop *sv, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	if (env != NULL)
	{
		sv->cmd->env = env;
		while (env[i] && ft_strncmp(env[i], "PATH=", 5))
			i++;
		if (env[i])
		{
			sv->cmd->path = ft_strsplit((tmp = ft_strdup(env[i] + 5)), ':');
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
}*/
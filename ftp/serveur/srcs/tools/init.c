#include <ftp_server.h>

/*
**	init_env = initialisation des variables d'env et sauvegarde du
**	dossier root et du path pour trouver les executables sans avoir a le
** 	faire tout le temps par la suite (cf. header pour voir ce qui est sur
**	la heap et ce qui est sur la stack.)
**
**	init_command_list : charge une liste de commandes autorisees sur
**	le server.
*/

void				init_sv_prop(t_sv_prop *sv, char *port, char **env)
{
	int				i;

	i = 0;
	sv->max = 0;
	sv->port = (unsigned short) ft_atoi(port);
	sv->cmd = (t_cmd *)ft_memalloc(sizeof(*(sv->cmd)));
	init_env(sv, env);
	init_command_list(sv);
	sv->fds = (t_fd *)ft_memalloc(sizeof(*(sv->fds)) * MAX_SOCKETS);
	while (i < MAX_SOCKETS)
		clean_fd(&(sv->fds[i++]));
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
	sv->cmd->bin = NULL;
	sv->cmd->cmda = NULL;
	sv->cmd->cmd = NULL;
}

void				init_command_list(t_sv_prop *sv)
{
	sv->cmd->bin = (t_bin *)ft_memalloc(sizeof(*sv->cmd->bin) * BIN_NB + 1);
	sv->cmd->bin[0]name = ft_strdup("ls");
	sv->cmd->bin[0].f = exe_command;
	sv->cmd->bin[1].name = ft_strdup("cd");
	sv->cmd->bin[1].f = bin_cd;
	sv->cmd->bin[2]name = ft_strdup("get");
	sv->cmd->bin[2].f = exe_command;
	sv->cmd->bin[3]name = ft_strdup("put");
	sv->cmd->bin[3].f = exe_command;
	sv->cmd->bin[4]name = ft_strdup("pwd");
	sv->cmd->bin[4].f = exe_command;
	sv->cmd->bin[5]name = ft_strdup("help");
	sv->cmd->bin[5].f = bin_help;
	sv->cmd->bin[6]name = ft_strdup("quit");
	sv->cmd->bin[6].f = sv_kill;
	sv->cmd->bin[BIN_NB] = 0;
}

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
	sv->left = 0;
	check_port(port);
	sv->port = (unsigned short)ft_atoi(port);
	sv->cmd = ft_memalloc(sizeof(*(sv->cmd)));
	init_env(sv, env);
	init_command_list(sv);
	sv->fds = ft_memalloc(sizeof(*(sv->fds)) * MAX_SOCKETS);
	while (i < MAX_SOCKETS)
	{
		clean_fd(&(sv->fds[i]));
		i++;
	}
}

/*
** Initialise l'env et la structure pour la gestion des lignes de
** commande
*/

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
	sv->cmd->cmda = NULL;
	sv->cmd->cmd = NULL;
	sv->cmd->gnl = NULL;
}

void				init_command_list(t_sv_prop *sv)
{
	sv->cmd->bin[CMD_LS].name = ft_strdup("ls");
	sv->cmd->bin[CMD_LS].f = exe_command;
	sv->cmd->bin[CMD_CD].name = ft_strdup("cd");
	sv->cmd->bin[CMD_CD].f = bin_cd;
	sv->cmd->bin[CMD_GET].name = ft_strdup("get");
	sv->cmd->bin[CMD_GET].f = bin_get;
	sv->cmd->bin[CMD_PWD].name = ft_strdup("pwd");
	sv->cmd->bin[CMD_PWD].f = bin_pwd;
	sv->cmd->bin[CMD_HELP].name = ft_strdup("help");
	sv->cmd->bin[CMD_HELP].f = bin_help;
	sv->cmd->bin[CMD_QUIT].name = ft_strdup("quit");
	sv->cmd->bin[CMD_QUIT].f = sv_kill;
}

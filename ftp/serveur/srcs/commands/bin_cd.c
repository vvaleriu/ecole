#include <ftp_server.h>

/*
int			ft_find_env(char *exe, char **env)
{
	int		i;
	int		j;
	char	*cmp;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (env[i][j] && env[i][j] != '=')
			j++;
		cmp = ft_strndup(env[i], j);
		if (!ft_strcmp(cmp, exe))
		{
			ft_strdel(&cmp);
			return (i);
		}
		ft_strdel(&cmp);
		i++;
		j = 0;
	}
	return (-1);
}*/

int				bin_cd(t_sv_prop *sv, int i)
{
	char	*prev_dir;
	char	*new_dir;

	i++;
	prev_dir = getcwd(NULL, BUF_CWD);
	if (sv->cmd->cmda[1])
	{
		if (chdir(sv->cmd->cmda[1]) != -1)
		{
			new_dir = getcwd(NULL, BUF_CWD);
			if (!ft_strstr(new_dir, sv->cmd->root_dir))
			{
				printf("%s\n", ERR_FORB_FOLDER);
				chdir(prev_dir);
				sv_send_message(i, ERR_FORB_FOLDER);
			}
			ft_strdel(&prev_dir);
			ft_strdel(&new_dir);
			sv_send_message(i, "DIR successfully changed.");
		}
		else
			printf("%s\n", ERR_FORB_FOLDER);
	}
	return (1);
}

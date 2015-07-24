#include <irc_client.h>

/*
** Check if the command is a client side command or it has to be transmitted to
** the server.
*/

int		is_client_side_command(t_cl_prop *cl, char *s)
{
	int		i;
	char	**cmda;

	i = 0;
	cmda = lexer(s);
	while (i < CL_BIN)
	{
		if (!ft_strncmp(cmda[0], cl->bin[i].name, ft_strlen(cl->bin[i].name)))
		{
			printf("[execution commande client]\n");
			cl->bin[i].f(cl, cmda);
			ft_strarray_del(&cmda);
			return (1);
		}
		i++;
	}
	return (0);
}
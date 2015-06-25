#include <ftp_client.h>

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
			printf("cmda : - cmda + 1 : %s\n", cmda);
			cl->bin[i].f(cl, cmda);
			ft_strarray_del(&cmda);
			return (1);
		}
		i++;
	}
	return (0);
}
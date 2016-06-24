#include <ftp_common.h>

void		check_port(char *port)
{
	int		port_int;
	char	*port_pt;

	port_pt = port;
	if (ft_strlen(port) > 5)
		E(-1, -1, ERR_INVALID_PORT, FORCE_EXIT);
	while (*port)
	{
		if (!ft_isdigit(*port))
			E(-1, -1, ERR_INVALID_PORT, FORCE_EXIT);
		port++;
	}
	if ((port_int = ft_atoi(port_pt)) > 65535)
	{
		E(-1, -1, ERR_INVALID_PORT_RANGE, FORCE_EXIT);
	}
}
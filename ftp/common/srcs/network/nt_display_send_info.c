#include <ftp_common.h>

int		nt_display_send_info(t_send_info info)
{
	static char *type[] = {"T_COMMAND", "T_BINARY", "T_OUTPUT"};

	printf("[nt_display_send_info] : [type : %s] [taille : %ld] [nom / commande : %s]\n",
		type[info.type], (long int)info.size, info.fname);
	return (1);
}
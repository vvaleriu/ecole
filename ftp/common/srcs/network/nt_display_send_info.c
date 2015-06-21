#include <ftp_common.h>

void		nt_display_send_info(t_send_info info)
{
	printf("[type : %d] [taille : %ld] [nom : %s]\n",
		info.type, (long int)info.size, info.fname);
}
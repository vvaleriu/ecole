#include <ftp_common.h>

void		clean_fd(t_fd *fd)
{
	fd->type = SK_FREE;
	fd->sock = 0;
	ft_memset(fd->rd, '\0', BUF_SIZE + 1);
	ft_memset(fd->wr, '\0', BUF_SIZE + 1);
	//ft_bzero(fd->rd, BUF_SIZE + 1);
	//ft_bzero(fd->wr, BUF_SIZE + 1);
	fd->ft_read = NULL;
	fd->ft_write = NULL;
}
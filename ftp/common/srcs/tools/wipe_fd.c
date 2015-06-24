#include <ftp_common.h>

/*
** clean the fd structure after a message or a file was sent
*/

void		wipe_fd(t_fd *fd)
{
	ft_bzero(fd->rd, BUF_SIZE + 1);
	ft_bzero(fd->wr, BUF_SIZE + 1);
}
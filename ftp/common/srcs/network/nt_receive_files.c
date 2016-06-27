#include <ftp_common.h>
#include <stdio.h>
#include <errno.h>

int			nt_receive_files(int sock, char *buf, t_send_info *info)
{
	int				fd;
	int				rd;
	long long int	to_read;
	long long int	already_read;

	already_read = 0;
	printf("[nt_receice_file]\n");
	if ((fd = open(info->fname, O_RDWR | O_CREAT | O_EXCL, 755)) > 0)
	{
		ft_printf("[open success]\n");
		while (already_read < info->size)
		{
			to_read = ((long int)info->size - already_read >= BUF_SIZE ? BUF_SIZE : (long int)info->size - already_read);
			rd = E(-1, recv(sock, buf, to_read, 0), ERR_RECV, NO_EXIT);
			already_read += rd;
			write(fd, buf, rd);
			printf("[%lld%%]\n", ((already_read * 100 / info->size)));
		}
		ft_printf("[files sent to the socket] [fsize: %lld] [sent size: %lld]\n", info->size, already_read);
		close(fd);
		ft_memset(buf, 0, BUF_SIZE);
	}
	else
	{
		printf("%s\n", ERR_WRITE_FILE);
		return (-1);
	}
	return (1);
}

/*int			nt_receive_files(int sock, t_send_info *info)
{
	int				fd;
	void			*file_map;

	if ((fd = open(info->fname, O_RDWR | O_CREAT | O_EXCL, 755)) > 0)
	{
		file_map = mmap(NULL, info->size, PROT_READ, MAP_SHARED, fd, 0);
		read(sock, file_map, info->size);
		ft_printf("[file received]\n");
	}
	else
	{		
		perror(errno);
		ft_printf("[error couldn't create file]\n");
		return (-1);
	}
	
	return (1);
}*/
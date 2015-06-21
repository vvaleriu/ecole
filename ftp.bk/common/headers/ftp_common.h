#ifndef COMMON_H
# define COMMON_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>

/*
**	SK_SERV, SK_CLIENT : Types contained in t_fd structure
**	SV_SOCK: macro to access server socket (= files descriptor) value
**	CL_SOCK(i): macro to access a client socket (= files descriptor) value
*/

# define ERR_USAGE			"usage"

# define SK_SERV			0
# define SK_CLIENT			1
# define SK_FREE			2

/*
**	BUF_SIZE: size of the buffer for read and write operation for each socket
*/

# define BUF_SIZE			4096

/*	
**	ERROR FUNCTIONS
**	Used in error checking functions
**	Tells the function wether an error has to exit or continue running the exe.
*/

# define E(e, r, s, q)		err_int(e, r, s, q)
# define EV(e, r, s, q)		err_void(e, r, s, q)
# define NO_EXIT			0
# define FORCE_EXIT			1

typedef struct s_fd			t_fd;
typedef struct s_pakinf		t_pakinf;

/*
**	sd: 		socket descriptor
**	type		SK_FREE	0, SK_SERV	1, SK_CLIENT	2
**	ft_read:	pointer on read function
**	ft_write:	pointer on write function
*/

struct			s_fd
{
	void	(*ft_read)();
	void	(*ft_write)();
	int		sock;
	int		type;
	char	rd[BUF_SIZE + 1];
	char	wr[BUF_SIZE + 1];
};

/*
**	sd: 		socket descriptor
**	type		0 message, 1 file, let the receiver chose the correct
**				treatment after reception
*/

struct			s_pakinf
{
	short		type;
	size_t		size;
	char		fname[512];
};

/*
**				ERROR MANAGEMENT
*/

void						usage(int target, int ac, char **av);
void						pterr(char *err);
int							err_int(int err, int res, char *str, int quit);
void						*err_void(void *err, void *res, char *str, int quit);

/*
**				SIGNAL MANAGEMENT
*/

void						sig_handler(int signo);

#endif
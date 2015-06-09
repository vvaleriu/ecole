#include <ft_server.h>

void		clean_socket(t_sock *s)
{
	s->type = SK_FREE;
	s->ft_read = NULL;
	s->ft_write = NULL;
}
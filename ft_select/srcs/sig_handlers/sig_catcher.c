#include <ft_select.h>

void			sig_catcher()
{

	signal(SIGINT, sig_handler);
	//signal(SIGTSTP, SIG_IGN);
	signal(SIGWINCH, resize_list);
}
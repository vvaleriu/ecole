#include <ft_select.h>

/*
** Terminal action when "return key" is pressed.
*/

void	handle_return(t_tconf *conf)
{
	if (tcsetattr(0, TCSADRAIN, &conf->def) == -1)
		ft_putendl("Error restoring default terminal capabilities.");
	exit_clean(conf);
	ft_putstr("\033[?1049l");
}
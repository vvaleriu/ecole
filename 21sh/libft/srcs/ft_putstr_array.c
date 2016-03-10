#include <libft.h>

void		ft_putstr_array(char **ar)
{
	int	i;

	i = 0;
	while (ar && ar[i] != '\0')
	{
		ft_putendl(ar[i]);
		i++;
	}
}
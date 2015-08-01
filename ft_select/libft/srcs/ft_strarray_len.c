#include <libft.h>

/*
** return 0 is no strings, returns -1 is ar == null
** returns number of strings in the array
*/

int      ft_strarray_len(char **ar)
{
    int     i;

    i = 0;
    if (ar)
    {
        while (ar[i])
            i++;
        return i;
    }
    return (-1);
}

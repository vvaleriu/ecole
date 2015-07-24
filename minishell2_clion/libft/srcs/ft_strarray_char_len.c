#include <libft.h>

/*
** return 0 is no strings, returns -1 is ar == null
** returns number of strings in the array
*/

int      ft_strarray_memsize(char **ar)
{
    int     str;
    int     bits;

    str = 0;
    bits = 0;
    if (ar)
    {
        while (ar[str])
        {
            bits += (ft_strlen(ar[str]) + 1);
            str++;
        }
        return str;
    }
    return (-1);
}

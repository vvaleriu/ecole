#include <libft.h>

/*
** return 0 is no strings, returns -1 is ar == null
** returns number of strings in the array
*/

int      ft_strarray_char_len(char **ar)
{
    int     i;
    int     len;

    i = 0;
    len = 0;
    if (ar)
    {
        while (ar[i])
        {
            len += (ft_strlen(ar[i]));
            i++;
        }
        return (len);
    }
    return (-1);
}

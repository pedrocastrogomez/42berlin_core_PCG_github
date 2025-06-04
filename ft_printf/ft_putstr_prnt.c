#include "ft_printf.h"

int	ft_putstr_prnt(void *str, int *count_chars)
{
    unsigned char   *s;
    int i;

    s = (unsigned char *)str;
    i = 0;
    while (s[i])
    {
    	if (write(1, &s[i], 1) == -1)
    		return (-1);
        (*count_chars) ++;
        i ++;
    }
    return (0);
}

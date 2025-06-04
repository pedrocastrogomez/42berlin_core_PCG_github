#include "libftprintf.h"

int	ft_putnbr_base_prnt_address(uintptr_t nb, int *count_chars, char *base)
{
	if ((size_t)nb >= ft_strlen(base))
	{
		ft_putnbr_base_prnt_address(nb / ft_strlen(base), count_chars, base);
		ft_putnbr_base_prnt_address(nb % ft_strlen(base), count_chars, base);
	}
	if ((size_t)nb < ft_strlen(base))
	{
		if (write(1, &base[nb], 1) == -1)
			return (-1);
		(*count_chars) ++;
	}
	return (0);
}

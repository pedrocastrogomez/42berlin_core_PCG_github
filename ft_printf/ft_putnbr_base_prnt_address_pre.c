#include "ft_printf.h"

int	ft_putnbr_base_prnt_address_pre(uintptr_t nb, int *count_chars, char *base, int prefix, int first_call)
{
	if (count_chars == NULL)
		return (-1);
	if (first_call && nb == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		(*count_chars) += 5;
		return (0);
	}
	if (prefix && first_call && nb != 0)
	{
		write(1, "0x", 2);
		(*count_chars) += 2;
	}
	if ((size_t)nb >= ft_strlen(base))
	{
		ft_putnbr_base_prnt_address_pre(nb / ft_strlen(base), count_chars, base, 0, 0);
		ft_putnbr_base_prnt_address_pre(nb % ft_strlen(base), count_chars, base, 0, 0);
	}
	if ((size_t)nb < ft_strlen(base))
	{
		if (write(1, &base[nb], 1) == -1)
			return (-1);
		(*count_chars) ++;
	}
	return (0);
}

#include "ft_printf.h"

static int	ft_intmin(char *base, int *count_chars)
{
	if (ft_strlen(base) == 16)
	{
		if (write (1, "-80000000", 9) == -1)
			return (-1);
		(*count_chars) += 9;
	}
	if (ft_strlen(base) == 10)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		(*count_chars) += 11;
	}
	return (0);
}

int	ft_putnbr_base_prnt(int nb, int *count_chars, char *base)
{
	if (nb == -2147483648)
	{
		ft_intmin(base, count_chars);
		return (0);
	}
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		(*count_chars) ++;
		nb = -nb;
	}
	if ((size_t)nb >= ft_strlen(base))
	{
		ft_putnbr_base_prnt(nb / ft_strlen(base), count_chars, base);
		ft_putnbr_base_prnt(nb % ft_strlen(base), count_chars, base);
	}
	if ((size_t)nb < ft_strlen(base))
	{
		if (write(1, &base[nb], 1) == -1)
			return (-1);
		(*count_chars) ++;
	}
	return (0);
}

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(char *format, ...);
int	ft_putchar_prnt(int c, int *count_chars);
int	ft_putstr_prnt(void *str, int *count_chars);
int	ft_putnbr_base_prnt(int nb, int *count_chars, char *base);

#endif

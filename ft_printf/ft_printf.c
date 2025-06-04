#include "ft_printf.h"
#include <stdio.h>

static int	ft_is_converter(char c)
{
	size_t	i;
    char    *str;
	
	str = "cspdiuxX";
	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static void ft_convert(char converter, va_list *ap, int *count_chars)
{
	char	*base10;
	char	*base16_lower;
	char	*base16_upper;
	int	flag;

    base10 = "0123456789";
    base16_lower = "0123456789abcdef";
    base16_upper = "0123456789ABCDEF";
    if (converter == 'c')
        flag = ft_putchar_prnt(va_arg(*ap, int), count_chars);
    else if (converter == 's')
        flag = ft_putstr_prnt(va_arg(*ap, char *), count_chars);
    else if (converter == 'p')
	{
		write(1, "0x", 2);
		(*count_chars) += 2;
        flag = ft_putnbr_base_prnt_address((uintptr_t)va_arg(*ap, void *), count_chars, base16_lower);
	}
    else if (converter == 'd' || converter == 'i')
        flag = ft_putnbr_base_prnt(va_arg(*ap, int), count_chars, base10);
    else if (converter == 'u')
    {
        flag = ft_putnbr_base_prnt_address(va_arg(*ap, unsigned int), count_chars, base10);
	}
	else if (converter == 'x')
        flag = ft_putnbr_base_prnt_address(va_arg(*ap, unsigned int), count_chars, base16_lower);
	else if (converter == 'X')
		flag = ft_putnbr_base_prnt_address(va_arg(*ap, unsigned int), count_chars, base16_upper);
	else
		flag = 0;
	if (flag == -1)
		*count_chars = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
    int count_chars;
	size_t	i;

    if (format == NULL)
        return ('\0');
    va_start(ap, format);
    count_chars = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_is_converter(format[i + 1]) == 1)
		{
			ft_convert(format[i + 1], &ap, &count_chars);
			if (count_chars == -1)
				return (count_chars);
			i += 2;
		}
        if (format[i] == '%' && format[i + 1] == '%')
        {
            i ++;
        }
		if (!(format[i] == '\0'))
		{
        	ft_putchar_prnt(format[i], &count_chars);
			i ++;
		}
	}
	va_end(ap);
    return (count_chars);
}

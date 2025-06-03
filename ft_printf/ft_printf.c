#include "libftprintf.h"

//printf returns the number of characters printed (
//excluding the null byte used to end output to strings).
//it is considered an error if mismatch between number of % and arguments.

//if write returns -1 then return error?


static int	ft_find(char *str, char c)
{
	size_t	i;
	
	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

int	ft_printf(char *format, ...)
{
	const char	*converter;
	size_t	arg_c;
	size_t	i;
	va_list	ap;

	converter = "cspdiuxX";
	arg_c = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_find(converter, format[i + 1]) == 1)
			arg_c ++;
		i ++;
	}
	if (arg_c > 0)
		va_start(ap, format);
		
		
}

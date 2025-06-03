#include "libftprintf.h"

//printf returns the number of characters printed (
//excluding the null byte used to end output to strings).
//it is considered an error if mismatch between number of % and arguments.

//if write returns -1 then return error?

//test commit history for git show

int	ft_printf(char *format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	arg_count;

	arg_count = 0;
	i = 0;
	while format[i] //this should be function that updates *argcount and returns array of datatypes based on their %...e.g all options in cspdiuxX% but xX should be unsigned?
	{
		if (format[i] == '%' && format[i + 1] != %)
		{
			argcount ++;
		}
	}
	if (arg_count == 0)
	{
		//write only format string but consider %%.
		return ();//return number of characters printed.
	}
	va_start(ap, format);
	arguments = ft_calloc(argcount, sizeof(void *));
	i = 0;
	while (i < arg_count) //this should be a function
	{
		arguments[i] = va_arg(ap, ft_type()); // ft_type(%?)  
		write(1, arguments[i], ft_strlen()); //function should change to string format before passed o write .....or use directly helper functions like ft_putnbr, etc. 
	}
	va_end(ap);
	//function to free each member in arguments, and the arguments array itself.
}

#include <stdio.h>
#include "libftprintf.h"
//ccw ft_printf.c ft_putchar_prnt.c ft_putstr_prnt.c ft_putnbr_base_prnt.c
int	main(void)
{
	int	flag1;
	int	flag2;
	int	nb = 12345;

	flag2 = ft_printf("%c. %s goes to address %p and at %d or %i celsius buys %u eggs ID %x or %X", 'A', "Manolo", &nb, -2, 3, 12, 12345, 12345);
    printf("\n");
    printf("%i\n", flag2);
    
    flag1 = printf("%c. %s goes to address %p and at %d or %i celsius buys %u eggs ID %x or %X", 'A', "Manolo", &nb, -2, 3, 12, 12345, 12345);
	printf("\n");
	printf("%i\n", flag1);
}

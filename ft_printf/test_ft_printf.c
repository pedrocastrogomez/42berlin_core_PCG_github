#include <stdio.h>
#include "ft_printf.h"
//ccw ft_printf.c ft_putchar_prnt.c ft_putstr_prnt.c ft_putnbr_base_prnt.c ft_putnbr_base_prnt_address.c libft/ft_strlen.c test_ft_printf.c

int	main(void)
{
	//unsigned int	c = 0;
	
	//int	flag1 = ft_printf("%p", &c);
	int	flag1 = ft_printf(" %p ", (void *)16);
	printf("\n");
    	printf("%i\n", flag1);

	//int	flag2 = ft_printf("%p", &c);
    	int	flag2 = printf(" %p ", (void *)16);
    	printf("\n");
	printf("%i\n", flag2);
//*/

	//unsigned int	c = 4294967295;
/*	
	int	flag1 = ft_printf("NULL %s NULL", (char *)NULL);
	printf("\n");
    	printf("%i\n", flag1);

    	int	flag2 = printf("NULL %s NULL", (char *)NULL);
    	printf("\n");
	printf("%i\n", flag2);
//*/

	//unsigned int	c = 4294967295;
/*
	int	flag1 = ft_printf("%x", 4294967295);
	printf("\n");
    	printf("%i\n", flag1);
    	
    	int	flag2 = printf("%x", 4294967295);
    	printf("\n");
	printf("%i\n", flag2);
//*/
/*
	//unsigned int	c = 4294967295;
	//int	d = -2147483648;
	
	int	flag1 = ft_printf("%u, %u", -2147483647, 4294967295);
	printf("\n");
    	printf("%i\n", flag1);
//*/
/*
    	int	flag2 = printf("%u, %u", -2147483647, 4294967295);
    	printf("\n");
	printf("%i\n", flag2);
	
//*/
/*
int nb = 3;


	int	flag1;
	flag1 = ft_printf("%c) ft_printf: %s goes to address %p and at %d or %i celsius buys a box of %u eggs ID %x or %X", 'A', "Manolo", &nb, -2, -3, 12, -2147483647, 4294967295);
    printf("\n");
    printf("%i\n", flag1);
//*/
/*
	int	flag2;
    flag2 = printf("%c) ...printf: %s goes to address %p and at %d or %i celsius buys a box of %u eggs ID %x or %X", 'B', "Manolo", &nb, -2, -3, 12, -2147483647, (unsigned int)4294967295);
	printf("\n");
	printf("%i\n", flag2);
//*/
}

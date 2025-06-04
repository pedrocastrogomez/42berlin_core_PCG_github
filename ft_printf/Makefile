CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -Ilibft
NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_putchar_prnt.c \
		ft_putstr_prnt.c \
		ft_putnbr_base_prnt.c \
		ft_putnbr_base_prnt_address.c \
		ft_putnbr_base_prnt_address_pre.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

TEMP_LIBFT_OBJS = temp_libft_objs

all : $(NAME)

$(LIBFT_LIB):
		$(MAKE) -C $(LIBFT_DIR)
	
$(NAME) : $(OBJS) $(LIBFT_LIB)
	mkdir -p $(TEMP_LIBFT_OBJS)
	cd $(TEMP_LIBFT_OBJS) && ar x ../$(LIBFT_LIB)
	ar rcs $(NAME) $(OBJS) $(TEMP_LIBFT_OBJS)/*.o
	rm -rf $(TEMP_LIBFT_OBJS)
	
%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o @

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
		rm -f $(NAME)
		$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean $(NAME)

.PHONY: clean fclean re bonus

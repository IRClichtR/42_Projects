NAME	= libftprintf.a

LIBFT_SRC	= $(wildcard libft/*.c)

PRINTF_SRC	= ft_nbrsize.c ft_hexasize.c arg_char.c arg_int.c arg_uint.c arg_ptr.c arg_hex.c arg_str.c ft_printf.c

LIBFT_OBJ	= $(LIBFT_SRC:.c=.o)

PRINTF_OBJ	= $(PRINTF_SRC:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror 

AR		= ar rc

all: ${NAME}

${NAME}: $(PRINTF_OBJ) $(LIBFT_OBJ)
	${AR} ${NAME} $(LIBFT_OBJ) $(PRINTF_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	${RM} ${PRINTF_OBJ}
	cd libft && ${MAKE} clean

fclean: clean
	${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re Makefile



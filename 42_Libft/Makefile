NAME	= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_calloc.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_memchr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c 

SC_BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_M	= ${SRCS:.c=.o}

OBJS_B	= ${SC_BONUS:.c=.o}

CC		= gcc

AR		= ar rc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}: 	${OBJS_M} 
	${AR} ${NAME} ${OBJS_M}
	@ranlib ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS_M} ${OBJS_B}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus: 	${OBJS_M} ${OBJS_B}
	${AR} ${NAME} ${OBJS_M} ${OBJS_B}

.PHONY: all, clean, fclean, re


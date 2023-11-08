NAME		= push_swap

CORE_SRC	= $(addprefix core_fcts/, main.c check_av.c    free_all.c    free_av.c push_swap.c   push_to_b.c \
sort_3.c sort_a_left.c	check_num.c   push_back.c   set_pile.c    sort_5.c)

SORT_SRC	= $(addprefix sort_utils/, check_if_push_comp.c find_bigger.c pb_mid2.c \
sort_pile.c check_if_sorted.c  pb_beg.c save_size.c	create_chunks.c pb_end.c \
select_idxb.c do_best_push.c pb_mid1.c select_move.c save_pile.c)

SWAP_SRC	= $(addprefix swap_utils/, find_biggest.c loop_ra.c loop_rrb.c \
rev_rotate_2.c find_idx.c find_smallest.c loop_rb.c loop_rrr.c rotate.c \
find_last.c ft_swap.c loop_rr.c push.c rotate_2.c value_at_idx.c find_next.c \
is_bigger.c loop_rra.c rev_rotate.c swap_pile.c)

PRINTF_SRC	= $(addprefix ft_printf/, arg_hex.c arg_ptr.c arg_uint.c ft_nbrsize.c \
arg_char.c arg_int.c arg_str.c ft_hexasize.c ft_printf.c)

LIBFT_SRC	= $(addprefix ft_printf/libft/, \
ft_itoa.c         ft_lstsize.c      ft_putstr_fd.c    ft_strmapi.c \
ft_atoi.c         ft_lstadd_back.c  ft_memchr.c       ft_split.c        ft_strncmp.c \
ft_bzero.c        ft_lstadd_front.c ft_memcmp.c       ft_strchr.c       ft_strnstr.c \
ft_calloc.c       ft_lstclear.c     ft_memcpy.c       ft_strdup.c       ft_strrchr.c \
ft_isalnum.c      ft_lstdelone.c    ft_memmove.c      ft_striteri.c     ft_strtrim.c \
ft_isalpha.c      ft_lstiter.c      ft_memset.c       ft_strjoin.c      ft_substr.c \
ft_isascii.c      ft_lstlast.c      ft_putchar_fd.c   ft_strlcat.c      ft_tolower.c \
ft_isdigit.c      ft_lstmap.c       ft_putendl_fd.c   ft_strlcpy.c      ft_toupper.c \
ft_isprint.c      ft_lstnew.c       ft_putnbr_fd.c    ft_strlen.c)

SRCS		= $(CORE_SRC) $(SORT_SRC) $(SWAP_SRC) $(PRINTF_SRC) $(LIBFT_SRC)

OBJS_DIR	= OBJS
OBJS		= $(addprefix $(OBJS_DIR)/, $(patsubst %.c, %.o, $(notdir $(SRCS))))

CC		= cc
CFLAGS		= -g -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: */%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all
clean: 
	rm -rf $(OBJS_DIR)
fclean: clean
	rm -f $(NAME)
.PHONY: all clean fclean re

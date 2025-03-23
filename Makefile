NAME = push_swap
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS = push_swap.c utils.c validation.c list_op.c sort.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT_LIB) $(NAME)

LFLAGS = -L$(LIBFT_DIR) -lft -lm -flto

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	
re: fclean all

debug: clean
	$(MAKE) CFLAGS='-Wall -Wextra -Werror -g' all
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -ffast-math -flto

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
      ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
      ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
      ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
      ft_strnstr.c ft_strrchr.c ft_substr.c ft_tolower.c ft_toupper.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  printf/ft_print_c.c printf/ft_print_d.c printf/ft_print_p.c \
	  printf/ft_print_s.c printf/ft_print_u.c printf/ft_print_x.c \
	  printf/ft_print_X.c printf/ft_printf.c get_next_line.c \
	  get_next_line_utils.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	-@mkdir -p $(OBJ_DIR)
	llvm-ar-12 rcs $(NAME) $(OBJS)
	llvm-ranlib-12 $(NAME)
	
$(NAME): $(OBJS)
	llvm-ar-12 rcs $(NAME) $(OBJS)
	llvm-ranlib-12 $(NAME)

$(OBJ_DIR)/%.o: %.c
	-@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: printf/%.c
	-@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re so


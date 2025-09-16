# **************************************************************************** #
# Libft Makefile para Linux (GCC)
# **************************************************************************** #

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
INCLUDE = include
NAME    = libft.a

# Lista de arquivos fonte
SRCS = src/ft_ctype/ft_isalnum.c \
       src/ft_ctype/ft_isalpha.c \
       src/ft_ctype/ft_isascii.c \
       src/ft_ctype/ft_isdigit.c \
       src/ft_ctype/ft_isprint.c \
       src/ft_ctype/ft_tolower.c \
       src/ft_ctype/ft_toupper.c \
       src/ft_linked_list/ft_lstadd_back.c \
       src/ft_linked_list/ft_lstadd_front.c \
       src/ft_linked_list/ft_lstclear.c \
       src/ft_linked_list/ft_lstdelone.c \
       src/ft_linked_list/ft_lstiter.c \
       src/ft_linked_list/ft_lstlast.c \
       src/ft_linked_list/ft_lstmap.c \
       src/ft_linked_list/ft_lstnew.c \
       src/ft_linked_list/ft_lstsize.c \
       src/ft_non_standard/ft_get_next_line/get_next_line.c \
       src/ft_non_standard/ft_get_next_line/get_next_line_bonus.c \
       src/ft_non_standard/ft_get_next_line/get_next_line_utils.c \
       src/ft_non_standard/ft_get_next_line/get_next_line_utils_bonus.c \
       src/ft_non_standard/ft_itoa.c \
       src/ft_non_standard/ft_putchar_fd.c \
       src/ft_non_standard/ft_putendl_fd.c \
       src/ft_non_standard/ft_putnbr_fd.c \
       src/ft_non_standard/ft_putstr_fd.c \
       src/ft_non_standard/ft_split.c \
       src/ft_non_standard/ft_striteri.c \
       src/ft_non_standard/ft_strjoin.c \
       src/ft_non_standard/ft_strmapi.c \
       src/ft_non_standard/ft_strtrim.c \
       src/ft_non_standard/ft_substr.c \
       src/ft_stdlib/ft_atoi.c \
       src/ft_stdlib/ft_calloc.c \
       src/ft_string/ft_bzero.c \
       src/ft_string/ft_memchr.c \
       src/ft_string/ft_memcmp.c \
       src/ft_string/ft_memcpy.c \
       src/ft_string/ft_memmove.c \
       src/ft_string/ft_memset.c \
       src/ft_string/ft_strchr.c \
       src/ft_string/ft_strdup.c \
       src/ft_string/ft_strlcat.c \
       src/ft_string/ft_strlcpy.c \
       src/ft_string/ft_strlen.c \
       src/ft_string/ft_strncmp.c \
       src/ft_string/ft_strnstr.c \
       src/ft_string/ft_strrchr.c

# Objetos correspondentes
OBJS = $(SRCS:.c=.o)

# **************************************************************************** #
# Regras principais
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

# **************************************************************************** #
# Limpeza
# **************************************************************************** #

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

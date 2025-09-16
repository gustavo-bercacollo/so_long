# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbercaco                                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 18:00:00 by gbercaco          #+#    #+#              #
# **************************************************************************** #

NAME_M = so_long
NAME_B = so_long_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# ---------------------------------------------------------------------------- #
# Sources
# ---------------------------------------------------------------------------- #

SRC_M = src/main.c \
        src/init.c \
        src/map_read.c \
        src/render.c \
        src/controls.c \
        src/free.c \
        src/validation.c \
        src/map_validate.c \
        src/map_checks.c \
        src/map_validate_characters.c \
        src/utils_map_validate.c \
        src/terminal_validations.c

SRC_B = bonus/src/main.c \
        bonus/src/handle_enemy.c \
        bonus/src/map_validate_characters.c \
        bonus/src/controls.c \
        bonus/src/render.c \
        bonus/src/map_read.c \
        bonus/src/init.c \
        bonus/src/map_checks.c \
        bonus/src/map_validate.c \
        bonus/src/utils_map_validate.c \
        bonus/src/free.c \
        bonus/src/validation.c \
        bonus/src/terminal_validations.c

OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

# ---------------------------------------------------------------------------- #
# Includes
# ---------------------------------------------------------------------------- #

INCLUDES = -I include -I bonus/include \
           -I libs/MLX42/include -I libs/libft/include

# ---------------------------------------------------------------------------- #
# Libraries
# ---------------------------------------------------------------------------- #

LIBFT_DIR = libs/libft
MLX42_DIR = libs/MLX42/build
LIBS = -L $(MLX42_DIR) -lmlx42 \
       -L $(LIBFT_DIR) -lft \
       -lglfw -lm -ldl -pthread

# ---------------------------------------------------------------------------- #
# Phony
# ---------------------------------------------------------------------------- #

.PHONY: all bonus clean fclean re

# ---------------------------------------------------------------------------- #
# Rules
# ---------------------------------------------------------------------------- #

all: $(NAME_M)

bonus: $(NAME_B)

# Compila libft
$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

# Compila MLX42 (garante que a pasta build exista)
$(MLX42_DIR)/libmlx42.a:
	mkdir -p $(MLX42_DIR)
	cd $(MLX42_DIR) && cmake .. && make -j4

# Executável mandatory
$(NAME_M): $(OBJ_M) $(LIBFT_DIR)/libft.a $(MLX42_DIR)/libmlx42.a
	$(CC) $(CFLAGS) $(OBJ_M) $(LIBS) -o $(NAME_M)

# Executável bonus
$(NAME_B): $(OBJ_B) $(LIBFT_DIR)/libft.a $(MLX42_DIR)/libmlx42.a
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBS) -o $(NAME_B)

# ---------------------------------------------------------------------------- #
# Compila objetos diretamente na pasta do fonte
# ---------------------------------------------------------------------------- #

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ---------------------------------------------------------------------------- #
# Limpar
# ---------------------------------------------------------------------------- #

clean:
	rm -f $(OBJ_M) $(OBJ_B)
	$(MAKE) -C $(LIBFT_DIR) clean
	[ -d $(MLX42_DIR) ] && $(MAKE) -C $(MLX42_DIR) clean || true

fclean: clean
	rm -f $(NAME_M) $(NAME_B)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MLX42_DIR)

re: fclean all

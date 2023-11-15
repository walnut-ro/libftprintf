# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Project name
NAME = libftprintf.a

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ../Libft
INCLUDE := includes/

# Source files
SRC_FILES = ft_print.c \
            ft_print_format.c
HFILES := $(INCLUDE)ft_printf.h

# Object files
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

# External library
LIBFT = $(LIBFT_DIR)/libft.a

# Targets
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_FILES)
    $(CC) $(CFLAGS) -o $@ $(OBJ_FILES) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HFILES)
    $(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(HFILES) -c $< -o $@

$(LIBFT):
    @make -C $(LIBFT_DIR)

clean:
    @make -C $(LIBFT_DIR) clean
    @rm -rf $(OBJ_DIR)

fclean: clean
    @make -C $(LIBFT_DIR) fclean
    @rm -f $(NAME)

re: fclean all

#
# rules not to mixed with similar file names
#

.PHONY: all clean fclean re

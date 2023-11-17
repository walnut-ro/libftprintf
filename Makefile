#
# names
#
NAME := libftprintf.a

AR := ar -crs

RM := rm -rf

CC := cc

CFLAGS := -Wall -Werror -Wextra

#
# rules not to mixed with similar file names
#
.PHONY: all bonus clean fclean re

#
# directories
#
INCLUDE := includes/

SRCS_DIR := srcs/

#
# necessary files
#
CFILES := ft_print_format.c \
			ft_print_number.c \
			ft_print_unsigned_number.c \
			ft_print_hex.c \
			ft_print_pointer.c\
			ft_print_str.c
HFILES := $(INCLUDE)ft_printf.h

SRCS := $(addprefix $(SRCS_DIR), $(CFILES) ft_print.c)

OBJS := $(SRCS:%.c=%.o)

#
# rules
#
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating library $@ from object files $^"
	$(AR) $@ $^

%.o: %.c $(HFILES)
	@echo "Compiling $< to create object file $@"
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

clean:
	$(RM) $(sort $(OBJS))

fclean: clean
	$(RM) $(NAME)

re: fclean all
#
# names
#
NAME := libftprintf.a

AR := ar rcs

RM := rm -rf

CC := cc

CFLAGS := -Wall -Werror -Wextra -g

#
# rules not to mixed with similar file names
#
.PHONY: all clean fclean re

#
# directories
#
INCLUDE := ./includes/

SRCS_DIR := ./srcs/

LIBFT := ./libft

OBJ_DIR := ./obj/

#
# necessary files
#
CFILES := ft_printf \
			ft_print_format \
			ft_print_number \
			ft_print_unsigned_number \
			ft_print_hex \
			ft_print_pointer \
			ft_print_str
HFILES := $(INCLUDE)ft_printf.h

SRCS := $(addprefix $(SRCS_DIR), $(addsuffix .c, $(CFILES)))

OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(CFILES)))

OBJF := $(OBJ_DIR).cache_exists

#
# rules
#
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating library $@ from object files $^"
	make bonus -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HFILES) | $(OBJF)
	@echo "Compiling $< to create object file $@"
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)
	touch $(OBJF)

clean:
	$(RM) -r $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all
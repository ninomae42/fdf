NAME := fdf

# source file settings
SRCS := main.c \
		validator.c \
		ft_syscall.c \
		hex_to_int.c \
		ft_split_utils.c \

SRCS_DIR := ./srcs
OBJS_DIR := ./objs
OBJS := $(SRCS:.c=.o)
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))

# library file settings
LIBFT := libft.a
LIBFT_DIR := ./libft
LIBFT := $(addprefix $(LIBFT_DIR)/, $(LIBFT))

MINILIBX := libmlx_Darwin.a
MINILIBX_DIR := ./minilibx-linux
MINILIBX := $(addprefix $(MINILIBX_DIR)/, $(MINILIBX))

LDFLAGS := -L/usr/X11R6/lib -lX11 -lXext -L$(MINILIBX_DIR) -lmlx -L$(LIBFT_DIR) -lft

# include file settings
INC_DIR := ./includes $(addprefix $(LIBFT_DIR)/, includes) $(MINILIBX_DIR)
INCLUDES := $(addprefix -I, $(INC_DIR))

# Command settings
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -fsanitize=address
MAKE := make
RM := rm -rf

# Makefile rules
all: $(NAME)

$(OBJS_DIR)/%o: $(SRCS_DIR)/%c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

norm:
	-@norminette includes/ | grep -v "INVALID_HEADER"
	-@norminette srcs/ | grep -v "INVALID_HEADER"
# -@norminette libft/ | grep -v "INVALID_HEADER"

.PHONY: all clean fclean re

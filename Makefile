NAME := fdf

SRCS_DIR := ./srcs
OBJS_DIR := ./obj
SRCS := main.c \
		hex_to_int.c \
		init.c \
		map_loader.c \
		map_utils.c \
		utils.c \

OBJS := $(SRCS:.c=.o)

SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))

# 依存ファイル.dを.oファイルから作る
DEPENDS := $(OBJS:.o=.d)

LIBFT_DIR := ./libft
LIBFT := libft.a

MINILIBX_DIR := ./minilibx-linux
MINILIBX := libmlx_Darwin.a

INC_DIR := ./includes $(addprefix $(LIBFT_DIR)/, includes) $(MINILIBX_DIR)
INCLUDES := $(addprefix -I, $(INC_DIR))

LIBS := $(LIBFT) $(MINILIBX)
LDFLAGS := -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit

CC := cc
CLAGS := -Wall -Wextra -Werror -g -MMD -MP
MAKE := make
RM := rm -rf

ifeq ($(MAKECMDGOALS), sanitize)
	CFLAGS += -fsanitize=address
endif

all: $(NAME)

$(OBJS_DIR)/%o: $(SRCS_DIR)/%c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@#$(CC) $(OBJS) -L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit libmlx_Darwin.a -o $(NAME)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(NAME)


clean:
	@#$(MAKE) clean -C $(LIBFT_DIR)
	@#$(MAKE) clean -C $(MINILIBX_DIR)
	@#$(RM) $(LIBS)
	$(RM) $(OBJS_DIR)

fclean: clean
	@#$(MAKE) fclean -C $(LIBFT_DIR)
	@#$(MAKE) fclean -C $(MINILIBX_DIR)
	$(RM) $(NAME)

re: fclean all

sanitize: re

run: all
	./fdf

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	mv $(addprefix $(LIBFT_DIR)/, $(LIBFT)) ./

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)
	mv $(addprefix $(MINILIBX_DIR)/, $(MINILIBX)) ./

.PHONY: all clean fclean re run

# 依存関係ファイル
-include $(DEPENDS)

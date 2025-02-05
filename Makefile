NAME= fdf
CC= cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFTDIR) -I$(MLX_LIB_DIR) -I /usr/X11/include
LDFLAGS = -L /usr/X11/lib -lX11 -lXext -lm
SRCS= main.c src/getmap.c src/colors.c src/utils.c src/drawing.c gnl/get_next_line.c gnl/get_next_line_utils.c src/events.c src/draw_utils.c
OBJS= $(SRCS:.c=.o)
MLX_LIB_DIR = minilibx
MLX_LIB = $(MLX_LIB_DIR)/libmlx_Linux.a
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX_LIB) $(LDFLAGS)
$(LIBFT):
	make -C $(LIBFTDIR)
$(MLX_LIB):
	make -C $(MLX_LIB_DIR)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(MLX_LIB_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)
	make clean -C $(MLX_LIB_DIR)
all: $(NAME)
re: fclean all
.PHONY: clean fclean all re

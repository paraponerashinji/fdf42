NAME= fdf
CC= cc
CFLAGS = -Wall -Wextra -Werror -Lmlx_linux -fPIE -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g
SRCS= main.c src/getmap.c src/colors.c src/utils.c src/drawing.c gnl/get_next_line.c gnl/get_next_line_utils.c src/events.c src/draw_utils.c
OBJS= $(SRCS:.c=.o)
LIBS=  libmlx.a libft.a
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
%.o:%.c fdfheader
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c
	cc -Wall -Wextra -Werror -fPIE -I/usr/include -Imlx_linux -O3 -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
all: $(NAME)
re: fclean all
.PHONY: clean fclean all re

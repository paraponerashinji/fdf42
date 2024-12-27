# Variables
NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz
LIBFT = -L. -lft

# Source files
SRC = main.c getmap.c colors.c utils.c drawing.c get_next_line.c get_next_line_utils.c events.c draw_utils.c
OBJ = $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

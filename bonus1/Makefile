CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
SRC = main.c so_long_utils.c so_long_utils2.c render_map.c \
	get_next_line_utils.c  get_next_line.c movs.c \
	verify_map.c ft_printf.c ft_printf_utils.c \
	animation.c

OBJS = $(SRC:.c=.o) 
MLX_FLAGS = -lmlx  -framework OpenGL -framework AppKit
 
all : $(NAME) clean

$(NAME): $(OBJS) so_long.h
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)  

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
	
re : fclean all
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
SRC = main.c render_map.c get_next_line_utils.c get_next_line.c movs.c verify_map.c
OBJS = $(SRC:.c=.o) 
MLX_FLAGS = -lmlx  -framework OpenGL -framework AppKit
 
all : $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS)  -o $(NAME)  

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJS)
fclean : clean
	$(RM) $(NAME)
	
re : fclean all
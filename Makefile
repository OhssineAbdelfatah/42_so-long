CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
NAMEB = so_long_bonus
SRC = ./mandatory/main.c ./mandatory/so_long_utils.c ./mandatory/so_long_utils2.c ./mandatory/render_map.c\
     ./mandatory/get_next_line_utils.c  ./mandatory/get_next_line.c ./mandatory/movs.c ./mandatory/verify_map.c\
      ./mandatory/ft_printf.c ./mandatory/ft_printf_utils.c 
SRCB = ./bonus/main.c ./bonus/so_long_utils.c ./bonus/so_long_utils2.c ./bonus/render_map.c \
    ./bonus/get_next_line_utils.c  ./bonus/get_next_line.c ./bonus/movs.c \
    ./bonus/verify_map.c ./bonus/ft_printf.c ./bonus/ft_printf_utils.c \
    ./bonus/animation.c ./bonus/move_enemy.c ./bonus/so_long_utils3.c
OBJS = $(SRC:.c=.o) 
OBJSB = $(SRCB:.c=.o) 
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
 
all : $(NAME)

bonus : $(NAMEB)

$(NAME) : $(OBJS) ./mandatory/so_long.h
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)  

$(NAMEB): $(OBJSB) ./bonus/so_long.h
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJSB) -o $(NAMEB)  

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJSB) $(OBJS) 

fclean : clean
	$(RM) $(NAME) $(NAMEB) 

re : fclean all
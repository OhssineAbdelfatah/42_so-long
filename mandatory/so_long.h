#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

// typedef struct all {
// 	t_img image;
// 	t_data data;
// } t_all;
typedef struct t_game
{
	int coll_0;
	int coll_var;
	int exit;
}t_game;

typedef struct t_img{
	char *path;
	void *img_ptr;
	int xw;
	int yh;

} t_img;

typedef struct t_map {
    int w;
    int h;
} t_map;

typedef struct s_data
{
	t_game *game;
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	t_img		*images[5]; // MLX image pointers (on the stack)
	t_map		*map; // Map pointer (contains map details - preferably kept on the stack)
	char **map_arr;
	int movs;
}	t_data;

// get next line functions
char	*get_next_line(int fd);
char	*ft_calloc(int count, int size);

char	*join(char *s1, char *s2);
int		ft_strlen(char *s);
int		find_char(char *s, char c);
char	*trim_line(char *s);
char	*hold_grbg(char *s);

// so long functions

//render map  
t_map count_hw();
char **fill_map(int h);
int render_map(t_data *data);
char *int_to_str(int nbr);

// movs

void move_left(t_data *data);
void move_up(t_data *data);
void move_right(t_data *data);
void move_down(t_data *data);
t_map get_player_position(t_data data);

// check collectable and exit

t_game count_collect(t_data *data);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:38:54 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/12 23:45:35 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_path
{
	int		col;
	int		exit;
}			t_path;

typedef struct s_object
{
	int		exit;
	int		player;
	int		coll;
}			t_obj;

typedef struct s_render
{
	int		x;
	int		y;
	int		i;
	int		j;
}			t_trender;

typedef struct s_game
{
	int		coll_0;
	int		coll_var;
	int		exit;
}			t_game;

typedef struct s_img
{
	char	*path;
	void	*img_ptr;
	int		xw;
	int		yh;
}			t_img;

typedef struct s_map
{
	int		w;
	int		h;
}			t_map;

typedef struct s_data
{
	t_game	*game;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	images[10];
	t_map	*map;
	char	**map_arr;
	int		movs;
	void	*canvas;
}			t_data;

// get next line functions
char		*get_next_line(int fd);
char		*ft_calloc(int count, int size);

char		*join(char *s1, char *s2);
int			ft_strlen(char *s);
int			find_char(char *s, char c);
char		*trim_line(char *s);
char		*hold_grbg(char *s);

// ft_printf functions

int			ft_printf(const char *string, ...);
void		printstr(char *s, int *len);
void		printchar(char c, int *len);
void		printnbr(long n, int *len, char type);
void		printhexa(unsigned long n, int *len, char type);

// so long functions

// verify map

int			check_lines(char **map_arr, t_map map);
int			check_boundry(char **map_arr, t_map map);
int			check_object(char **map_arr, t_map mtrx, t_obj obj);
int			check_map_name(char *name);
int			check_valid_path(char *name);

// render map
t_map		count_hw(char *name);
char		**fill_map(int h, char *name);
int			render_map(t_data *data);
char		*int_to_str(int nbr);
void		put_to_win(t_data data, t_trender ren);

// movs

void		move_left(t_data *data);
void		move_up(t_data *data);
void		move_right(t_data *data);
void		move_down(t_data *data);
t_map		get_player_position(char **map_arr);

// utils

int			get_button_exit(int keycode, t_data vars);
t_game		count_collect(char **map_arr);
void		free_map(char **map_arr);
int			check_errors(char *name);
void		throw_error(char *error, int i);

#endif

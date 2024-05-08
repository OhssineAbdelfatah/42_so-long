/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:05:03 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/08 17:11:35 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	get_movs(long keycode, t_data *vars)
{
	if (keycode == 53)
		throw_error("game aborted.", 1);
	if (keycode == 124 || keycode == 2)
	{
		(*vars).canvas = (*vars).images[5].img_ptr;
		move_right(vars);
	}
	if (keycode == 123 || keycode == 0)
	{
		(*vars).canvas = (*vars).images[6].img_ptr;
		move_left(vars);
	}
	if (keycode == 126 || keycode == 13)
	{
		(*vars).canvas = (*vars).images[7].img_ptr;
		move_up(vars);
	}
	if (keycode == 125 || keycode == 1)
	{
		(*vars).canvas = (*vars).images[8].img_ptr;
		move_down(vars);
	}
	return (0);
}

t_data	init_imgs(t_data data)
{
	t_img	img[17];
	int		i;

	i = -1;
	img[0].path = "./texteurs/wall.xpm";
	img[1].path = "./texteurs/col.xpm";
	img[2].path = "./texteurs/close.xpm";
	img[3].path = "./texteurs/open.xpm";
	img[4].path = "./texteurs/floor.xpm";
	img[5].path = "./texteurs/right_p.xpm";
	img[6].path = "./texteurs/left_p.xpm";
	img[7].path = "./texteurs/up_p.xpm";
	img[8].path = "./texteurs/down_p.xpm";
	img[9].path = "./texteurs/anim1/explosion1.xpm";
	img[10].path = "./texteurs/anim1/explosion2.xpm";
	img[11].path = "./texteurs/anim1/explosion3.xpm";
	img[12].path = "./texteurs/anim1/explosion4.xpm";
	img[13].path = "./texteurs/anim1/explosion5.xpm";
	img[14].path = "./texteurs/anim1/explosion6.xpm";
	img[15].path = "./texteurs/anim1/explosion7.xpm";
	img[16].path = "./texteurs/anim1/explosion8.xpm";
	while (++i < 17)
	{
		data.images[i] = img[i];
		data.images[i].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
				data.images[i].path, &(data.images[i].xw),
				&(data.images[i].yh));
		if (!(data.images[i].img_ptr))
			throw_error("error getting images.", 1);
	}
	data.canvas = data.images[5].img_ptr;
	return (data);
}

int	start_game(char *name)
{
	t_data	data;
	t_game	game;
	t_map	mtrx;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		throw_error("mlx connection init fails.", 1);
	mtrx = count_hw(name);
	data = init_imgs(data);
	data.map = &mtrx;
	data.map_arr = fill_map(mtrx.h, name);
	data.fire = count_enm(data);
	data.fire_arr = get_enm(data);
	(data).win_ptr = mlx_new_window((data).mlx_ptr, (data).map->w
			* data.images[0].xw, (data).map->h * data.images[0].yh,
			"So Long @_@");
	if (data.win_ptr == NULL)
		throw_error("mlx window init fails.", 1);
	game = count_collect(data.map_arr);
	data.game = &game;
	data.movs = 0;
	render_map(&data);
	mlx_hook(data.win_ptr, 2, 0, get_movs, &data);
	mlx_hook(data.win_ptr, 17, 0, get_button_exit, &data);
	mlx_loop_hook(data.mlx_ptr, fire, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	int	err;

	if (argc == 2)
	{
		check_errors(argv[1]);
		err = start_game(argv[1]);
		if (err != 0)
			return (0);
	}
	else
		throw_error("arguments too few, or too many.", 1);
	return (0);
}

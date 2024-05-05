/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:33:55 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/05 15:40:59 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(int h, char *name)
{
	char	**map;
	int		i;
	int		fd_map;

	fd_map = open(name, O_RDONLY);
	if (fd_map == -1)
		throw_error("file not exist or incorrect permission.", 1);
	map = (char **)malloc((h + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	map[0] = get_next_line(fd_map);
	if (!map[0])
	{
		free(map);
		throw_error("file empty.", 1);
	}
	i = 1;
	while (i < h)
	{
		map[i] = get_next_line(fd_map);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	wall_then_player(t_data dt, t_trender rn)
{
	mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, dt.images[5].img_ptr, rn.x,
		rn.y);
	mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, dt.images[3].img_ptr, rn.x,
		rn.y);
	mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, dt.canvas, rn.x, rn.y);
}

void	floor_then_obj(t_data dt, t_trender rn, void *ptr)
{
	mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, dt.images[5].img_ptr, rn.x,
		rn.y);
	mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, ptr, rn.x, rn.y);
}

void	put_to_win(t_data dt, t_trender rn)
{
	if (dt.map_arr[rn.i][rn.j] == '1')
		mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, dt.images[0].img_ptr,
			rn.x, rn.y);
	else if (dt.map_arr[rn.i][rn.j] == '0')
		mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, dt.images[5].img_ptr,
			rn.x, rn.y);
	else if (dt.map_arr[rn.i][rn.j] == 'P')
		floor_then_obj(dt, rn, dt.canvas);
	else if (dt.map_arr[rn.i][rn.j] == 'C')
		floor_then_obj(dt, rn, dt.images[2].img_ptr);
	else if (dt.map_arr[rn.i][rn.j] == 'E'
		&& dt.game->coll_var != dt.game->coll_0)
		floor_then_obj(dt, rn, dt.images[3].img_ptr);
	else if (dt.map_arr[rn.i][rn.j] == 'E'
		&& dt.game->coll_var == dt.game->coll_0)
		floor_then_obj(dt, rn, dt.images[4].img_ptr);
	else if (dt.map_arr[rn.i][rn.j] == 'B')
		wall_then_player(dt, rn);
}

int	render_map(t_data *data)
{
	t_trender	ren;

	ren.y = 0;
	ren.i = 0;
	while ((*data).map_arr[ren.i])
	{
		ren.x = 0;
		ren.j = 0;
		while ((*data).map_arr[ren.i][ren.j])
		{
			put_to_win(*data, ren);
			ren.j++;
			ren.x += (*data).images[0].xw;
		}
		ren.y += (*data).images[0].yh;
		ren.i++;
	}
	if ((*data).movs != 0)
		ft_printf("mov number : %d \n", (*data).movs);
	return (0);
}

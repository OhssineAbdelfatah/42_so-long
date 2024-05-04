/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:33:35 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/04 13:17:04 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_lines(char **map_arr, t_map map)
{
	int	i;

	i = 0;
	while (map_arr && i + 1 < (map.h))
	{
		if (ft_strlen(map_arr[i]) != ft_strlen(map_arr[i + 1]))
		{
			ft_printf("lines error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_boundry(char **map_arr, t_map map)
{
	int	i;

	i = 0;
	while (map_arr[0][i] != '\0' && map_arr[map.h - 1][i] != '\0')
	{
		if (map_arr[0][i] != '1' || map_arr[map.h - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (map_arr && map_arr[i] != NULL)
	{
		if (map_arr[i][0] != '1' || map_arr[i][map.w - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_object(char **map_arr)
{
	t_obj	obj;
	t_map	mtrx;

	mtrx.h = 0;
	obj.exit = 0;
	obj.player = 0;
	obj.coll = 0;
	while (map_arr && map_arr[mtrx.h])
	{
		mtrx.w = 0;
		while (map_arr[mtrx.h][mtrx.w])
		{
			if (map_arr[mtrx.h][mtrx.w] == 'P')
				obj.player++;
			else if (map_arr[mtrx.h][mtrx.w] == 'E')
				obj.exit++;
			else if (map_arr[mtrx.h][mtrx.w] == 'C')
				obj.coll++;
			mtrx.w++;
		}
		mtrx.h++;
	}
	if (obj.player != 1 || obj.exit != 1 || obj.coll < 1)
		return (-1);
	return (0);
}

int	valid_path(t_map pos, int *col, int *exit, char **map_arr)
{
	if (map_arr[pos.h][pos.w] == '1' || map_arr[pos.h][pos.w] == '\0'
		|| map_arr[pos.h] == NULL || map_arr[pos.h][pos.w] == 'V')
		return (0);
	if (map_arr[pos.h][pos.w] == 'C')
		*col += 1;
	if (map_arr[pos.h][pos.w] != 'E')
		*exit = 1;
	map_arr[pos.h][pos.w] = 'V';
	// ft_printf("here\n");
	pos.h += 1;
    valid_path(pos, col, exit, map_arr);
    pos.h -= 2;
    valid_path(pos, col, exit, map_arr);
    pos.h += 2;
    valid_path(pos, col, exit, map_arr);
    pos.w -= 2;
    valid_path(pos, col, exit, map_arr);
    pos.w += 1;
	// valid_path((t_map){pos.h + 1, pos.w}, col, exit, map_arr);
	// valid_path((t_map){pos.h - 1, pos.w}, col, exit, map_arr);
	// valid_path((t_map){pos.h, pos.w + 1}, col, exit, map_arr);
	// valid_path((t_map){pos.h, pos.w - 1}, col, exit, map_arr);
	return (0);
}

int	check_valid_path(char *name)
{
	char	**map_arr;
	t_map	p_pos;
	int		col;
	int		exit;
	int		col_0;

	col = 0;
	exit = 0;
	map_arr = fill_map(count_hw(name).h, name);
	col_0 = count_collect(map_arr).coll_0;
	p_pos = get_player_position(map_arr);
	valid_path(p_pos, &col, &exit, map_arr);
	// free_map(map_arr);
	if (col != col_0 || exit != 1)
	{
		// throw_error("invalid path.", 1);
		return -1;
	}
	return (0);
}
// col lines

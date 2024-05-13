/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:58:44 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/10 19:03:29 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	count_collect(char **map_arr)
{
	int		i;
	int		j;
	t_game	g1;

	i = 0;
	g1.coll_0 = 0;
	g1.coll_var = 0;
	g1.exit = 0;
	while (map_arr && map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (map_arr[i][j] == 'C')
				g1.coll_0++;
			j++;
		}
		i++;
	}
	return (g1);
}

int	get_button_exit(int keycode, t_data vars)
{
	(void)keycode;
	(void)vars;
	throw_error("game exit.", 1);
	return (0);
}

t_map	get_player_position(char **map)
{
	t_map	mtrx;
	int		i;
	int		j;

	mtrx.h = 0;
	mtrx.w = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'B')
			{
				mtrx.h = i;
				mtrx.w = j;
				return (mtrx);
			}
			j++;
		}
		i++;
	}
	return (mtrx);
}

void	free_map(char **map_arr)
{
	int	i;

	i = 0;
	while (map_arr[i])
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
	return ;
}

int	check_errors(char *name)
{
	t_map	map;
	char	**map_arr;

	map = count_hw(name);
	if (map.h > 21 || map.w > 40)
		throw_error("hight or width error.", 1);
	map_arr = fill_map(map.h, name);
	if (check_map_name(name) == -1)
		throw_error("map file name not correct.", 1);
	if (check_lines(map_arr, map) == -1)
		throw_error("lines not eqaul.", 1);
	if (check_boundry(map_arr, map) == -1)
		throw_error("side walls.", 1);
	if (check_object(map_arr) == -1)
		throw_error("too few or too many objects.", 1);
	if (check_valid_path(name) == -1)
		throw_error("invalid path.", 1);
	return (0);
}

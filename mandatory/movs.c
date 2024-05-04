/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:58:32 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/03 19:57:25 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_data *data)
{
	t_map	loc;

	loc = get_player_position(data->map_arr);
	if (loc.w - 1 > 0 && (*data).map_arr[loc.h][loc.w - 1] != '1')
	{
		(*data).movs++;
		if ((*data).map_arr[loc.h][loc.w - 1] == 'C')
			(*data).game->coll_var++;
		if ((*data).map_arr[loc.h][loc.w - 1] == 'E'
			&& (*data).game->coll_var != (*data).game->coll_0)
			(*data).map_arr[loc.h][loc.w - 1] = 'B';
		else if ((*data).map_arr[loc.h][loc.w - 1] == 'E'
			&& (*data).game->coll_var == (*data).game->coll_0)
			throw_error("you win", 2);
		else
			(*data).map_arr[loc.h][loc.w - 1] = 'P';
		if ((*data).map_arr[loc.h][loc.w] == 'B')
			(*data).map_arr[loc.h][loc.w] = 'E';
		else
			(*data).map_arr[loc.h][loc.w] = '0';
		render_map(data);
	}
	return ;
}

void	move_right(t_data *data)
{
	t_map	loc;

	loc = get_player_position(data->map_arr);
	if (loc.w + 1 > 0 && (*data).map_arr[loc.h][loc.w + 1] != '1')
	{
		(*data).movs++;
		if ((*data).map_arr[loc.h][loc.w + 1] == 'C')
			(*data).game->coll_var++;
		if ((*data).map_arr[loc.h][loc.w + 1] == 'E'
			&& (*data).game->coll_var != (*data).game->coll_0)
			(*data).map_arr[loc.h][loc.w + 1] = 'B';
		else if ((*data).map_arr[loc.h][loc.w + 1] == 'E'
			&& (*data).game->coll_var == (*data).game->coll_0)
			throw_error("you win", 2);
		else
			(*data).map_arr[loc.h][loc.w + 1] = 'P';
		if ((*data).map_arr[loc.h][loc.w] == 'B')
			(*data).map_arr[loc.h][loc.w] = 'E';
		else
			(*data).map_arr[loc.h][loc.w] = '0';
		render_map(data);
	}
	return ;
}

void	move_down(t_data *data)
{
	t_map	loc;

	(*data).canvas = (*data).images[9].img_ptr;
	loc = get_player_position(data->map_arr);
	if (loc.h + 1 > 0 && (*data).map_arr[loc.h + 1][loc.w] != '1')
	{
		(*data).movs++;
		if ((*data).map_arr[loc.h + 1][loc.w] == 'C')
			(*data).game->coll_var++;
		if ((*data).map_arr[loc.h + 1][loc.w] == 'E'
			&& (*data).game->coll_var != (*data).game->coll_0)
			(*data).map_arr[loc.h + 1][loc.w] = 'B';
		else if ((*data).map_arr[loc.h + 1][loc.w] == 'E'
			&& (*data).game->coll_var == (*data).game->coll_0)
			throw_error("you win", 2);
		else
			(*data).map_arr[loc.h + 1][loc.w] = 'P';
		if ((*data).map_arr[loc.h][loc.w] == 'B')
			(*data).map_arr[loc.h][loc.w] = 'E';
		else
			(*data).map_arr[loc.h][loc.w] = '0';
		render_map(data);
	}
	return ;
}

void	move_up(t_data *data)
{
	t_map	loc;

	(*data).canvas = (*data).images[8].img_ptr;
	loc = get_player_position(data->map_arr);
	if (loc.h - 1 > 0 && (*data).map_arr[loc.h - 1][loc.w] != '1')
	{
		(*data).movs++;
		if ((*data).map_arr[loc.h - 1][loc.w] == 'C')
			(*data).game->coll_var++;
		if ((*data).map_arr[loc.h - 1][loc.w] == 'E'
			&& (*data).game->coll_var != (*data).game->coll_0)
			(*data).map_arr[loc.h - 1][loc.w] = 'B';
		else if ((*data).map_arr[loc.h - 1][loc.w] == 'E'
			&& (*data).game->coll_var == (*data).game->coll_0)
			throw_error("you win", 2);
		else
			(*data).map_arr[loc.h - 1][loc.w] = 'P';
		if ((*data).map_arr[loc.h][loc.w] == 'B')
			(*data).map_arr[loc.h][loc.w] = 'E';
		else
			(*data).map_arr[loc.h][loc.w] = '0';
		render_map(data);
	}
	return ;
}

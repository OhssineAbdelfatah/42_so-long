/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:56:39 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/12 20:44:04 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_floor(char c)
{
	if (c != '1' && c != 'C' && c != 'X' && c != 'E')
		return (1);
	else
		return (0);
}

void	check_direction(t_data dt, int k, int *flag)
{
	if (!is_floor(dt.map_arr[dt.fire_arr[k].h][dt.fire_arr[k].w - 1]))
		*flag = 0;
	else if (!is_floor(dt.map_arr[dt.fire_arr[k].h][dt.fire_arr[k].w + 1]))
		*flag = 1;
	return ;
}

void	move_enemy(t_data *dt)
{
	int			k;
	static int	flag;

	k = -1;
	count_enm(dt);
	while (++k < (dt->fire))
	{
		if (dt->map_arr[dt->fire_arr[k].h][dt->fire_arr[k].w - 1] == 'P'
			|| dt->map_arr[dt->fire_arr[k].h][dt->fire_arr[k].w + 1] == 'P')
			throw_error("you lose.", 1);
		check_direction(*dt, k, &flag);
		if (is_floor(dt->map_arr[dt->fire_arr[k].h][dt->fire_arr[k].w - 1])
			&& flag == 1)
		{
			((*dt).map_arr[(*dt).fire_arr[k].h][(*dt).fire_arr[k].w - 1]) = 'X';
			((*dt).map_arr[(*dt).fire_arr[k].h][(*dt).fire_arr[k].w]) = '0';
		}
		if (is_floor((*dt).map_arr[(*dt).fire_arr[k].h][(*dt).fire_arr[k].w
				+ 1]) && flag == 0)
		{
			(*dt).map_arr[(*dt).fire_arr[k].h][(*dt).fire_arr[k].w + 1] = 'X';
			(*dt).map_arr[(*dt).fire_arr[k].h][(*dt).fire_arr[k].w] = '0';
		}
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:09:51 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/12 20:35:49 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_imgs(t_data dt, void *img_ptr)
{
	int	k;

	k = 0;
	while (k < (dt.fire))
	{
		mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, dt.images[4].img_ptr,
			dt.fire_arr[k].w * 64, dt.fire_arr[k].h * 64);
		mlx_put_image_to_window(dt.mlx_ptr, dt.win_ptr, img_ptr,
			dt.fire_arr[k].w * 64, dt.fire_arr[k].h * 64);
		k++;
	}
	return ;
}

void	put_animation(t_data data, int j)
{
	if (j == 0)
		put_imgs(data, data.anim[0].img_ptr);
	if (j == 1500)
		put_imgs(data, data.anim[1].img_ptr);
	if (j == 3000)
		put_imgs(data, data.anim[2].img_ptr);
	if (j == 4500)
		put_imgs(data, data.anim[3].img_ptr);
	if (j == 6000)
		put_imgs(data, data.anim[4].img_ptr);
	if (j == 7500)
		put_imgs(data, data.anim[5].img_ptr);
	if (j == 9000)
		put_imgs(data, data.anim[6].img_ptr);
	if (j == 10500)
		put_imgs(data, data.anim[7].img_ptr);
}

int	animation(t_data *data)
{
	static int	j = 0;

	count_enm(data);
	data->fire_arr = get_enm(*data);
	put_animation(*data, j);
	if (j == 12000)
	{
		move_enemy(data);
		render_map(data);
		j = 0;
	}
	free(data->fire_arr);
	j++;
	return (0);
}

void	count_enm(t_data *dt)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (dt->map_arr[i])
	{
		j = 0;
		while (dt->map_arr[i][j])
		{
			if (dt->map_arr[i][j] == 'X')
				k++;
			j++;
		}
		i++;
	}
	dt->fire = k;
	return ;
}

t_map	*get_enm(t_data dt)
{
	int		i;
	int		j;
	int		t;
	t_map	*enm;

	enm = malloc((dt.fire) * sizeof(t_map));
	if (!enm)
		throw_error("malloc failed.", 1);
	i = -1;
	t = 0;
	while (dt.map_arr[++i])
	{
		j = -1;
		while (dt.map_arr[i][++j])
		{
			if (dt.map_arr[i][j] == 'X' && t < dt.fire)
			{
				enm[t].h = i;
				enm[t].w = j;
				t++;
			}
		}
	}
	return (enm);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:09:51 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/08 17:13:15 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_obj(t_data *data, void *img, t_map mtrx)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->images[4].img_ptr, mtrx.h * 64, mtrx.w * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, mtrx.h * 64,
		mtrx.w * 64);
}

int	fire(t_data *data)
{
	static int	j = 0;
	int			k;

	k = 0;
	if (j == 0)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[9].img_ptr, data->fire_arr[k]);
			k++;
		}
	}
	else if (j == 1500)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[10].img_ptr, data->fire_arr[k]);
			k++;
		}
	}
	else if (j == 3000)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[11].img_ptr, data->fire_arr[k]);
			k++;
		}
	}
	else if (j == 4500)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[12].img_ptr, data->fire_arr[k]);
			k++;
		}
	}
	else if (j == 6000)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[13].img_ptr, data->fire_arr[k]);
			k++;
		}
	}
	else if (j == 7500)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[14].img_ptr, data->fire_arr[k]);
			k++;
		}
	}
	else if (j == 9000)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[15].img_ptr, data->fire_arr[k]);
			k++;
		}
	}
	else if (j == 10500)
	{
		while (k < data->fire)
		{
			put_obj(data, data->images[16].img_ptr, data->fire_arr[k]);
			k++;
		}
		j = 0;
	}
	j++;
	return (0);
}

t_map	find_enemy(t_data *data)
{
	t_map	mtrx;
	int		i;
	int		j;

	mtrx.h = 0;
	mtrx.w = 0;
	i = 0;
	while (data->map_arr[i])
	{
		j = 0;
		while (data->map_arr[i][j])
		{
			if (data->map_arr[i][j] == 'X')
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

int	count_enm(t_data dt)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (dt.map_arr[i])
	{
		j = 0;
		while (dt.map_arr[i][j])
		{
			if (dt.map_arr[i][j] == 'X')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

t_map	*get_enm(t_data dt)
{
	int		i;
	int		j;
	int		k;
	int		t;
	t_map	*enm;

	k = count_enm(dt);
	enm = malloc(k * sizeof(t_map));
	if (!enm)
		throw_error("malloc failed.", 1);
	i = 0;
	t = 0;
	while (dt.map_arr[i])
	{
		j = 0;
		while (dt.map_arr[i][j])
		{
			if (dt.map_arr[i][j] == 'X' && t < k)
			{
				enm[t].h = j;
				enm[t].w = i;
				t++;
			}
			j++;
		}
		i++;
	}
	return (enm);
}

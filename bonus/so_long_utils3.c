/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:28:51 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/12 23:46:57 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printf_movs(t_data data)
{
	char	*movs;

	movs = int_to_str(data.movs);
	mlx_string_put(data.mlx_ptr, data.win_ptr, 64, 20, 0xffffff, "movs :");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 128, 20, 0xffffff, movs);
	free(movs);
}

t_data	init_anim(t_data data)
{
	t_img	img[8];
	int		i;

	img[0].path = "./texteurs_bonus/anim1/explosion1.xpm";
	img[1].path = "./texteurs_bonus/anim1/explosion2.xpm";
	img[2].path = "./texteurs_bonus/anim1/explosion3.xpm";
	img[3].path = "./texteurs_bonus/anim1/explosion4.xpm";
	img[4].path = "./texteurs_bonus/anim1/explosion5.xpm";
	img[5].path = "./texteurs_bonus/anim1/explosion6.xpm";
	img[6].path = "./texteurs_bonus/anim1/explosion7.xpm";
	img[7].path = "./texteurs_bonus/anim1/explosion8.xpm";
	i = -1;
	while (++i < 8)
	{
		data.anim[i] = img[i];
		data.anim[i].img_ptr = mlx_xpm_file_to_image(data.mlx_ptr,
				data.anim[i].path, &(data.anim[i].xw), &(data.anim[i].yh));
		if (!(data.anim[i].img_ptr))
			throw_error("error getting images.", 1);
	}
	return (data);
}

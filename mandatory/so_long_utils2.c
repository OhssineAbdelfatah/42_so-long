/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:43:01 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/04 11:49:54 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_int_len(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	else
	{
		while (num)
		{
			num = num / 10;
			len++;
		}
	}
	return (len);
}

char	*int_to_str(int nbr)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	len = count_int_len(nbr);
	str = malloc(len + 1);
	while (i < len)
	{
		str[len - 1 - i] = nbr % 10 + 48;
		nbr /= 10;
		i++;
	}
	str[len] = 0;
	return (str);
}

void	throw_error(char *error, int i)
{
	if (i == 1)
	{
		ft_printf("\033[1m\033[31m");
		ft_printf("error !\n%s\n", error);
		ft_printf("\033[0;m");
		exit(-1);
	}
	else if (i == 2)
	{
		ft_printf("\033[1m\033[32m");
		ft_printf("%s\n", error);
		ft_printf("\033[0;m");
		exit(-1);
	}
}

t_map	count_hw(char *name)
{
	int		fd_map;
	t_map	mtrx;
	char	*line;

	mtrx.w = 0;
	mtrx.h = 0;
	fd_map = open(name, O_RDONLY);
	if (fd_map == -1)
		throw_error("file not exist or incorrect permission.", 1);
	while (1)
	{
		line = get_next_line(fd_map);
		if (line == NULL)
			break ;
		while (line[mtrx.w])
			mtrx.w++;
		mtrx.h++;
		free(line);
	}
	free(line);
	close(fd_map);
	return (mtrx);
}

int	check_map_name(char *name)
{
	int		i;
	int		j;
	int		k;
	char	*ext;

	ext = ".ber";
	i = 0;
	k = 3;
	while (name[i++])
		;
	j = i;
	i--;
	while (i-- > j - 4)
	{
		if (name[i] != ext[k])
		{
			return (-1);
		}
		k--;
	}
	return (0);
}

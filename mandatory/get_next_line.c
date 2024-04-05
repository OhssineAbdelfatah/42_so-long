/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:11:16 by aohssine          #+#    #+#             */
/*   Updated: 2024/04/02 13:35:30 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_calloc(int count, int size)
{
	char	*ptr;
	char	*p;
	int		len;

	if (count == 0 || size == 0)
		return (NULL);
	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	len = count * size;
	p = ptr;
	while (len--)
		*p++ = '\0';
	return (ptr);
}

char	*read_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	bf;

	bf = 1;
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	while (bf > 0)
	{
		bf = read(fd, line, BUFFER_SIZE);
		if (bf == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line[bf] = '\0';
		buffer = join(buffer, line);
		if (find_char(line, '\n'))
			break ;
	}
	free(line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = trim_line(buffer);
	buffer = hold_grbg(buffer);
	return (line);
}

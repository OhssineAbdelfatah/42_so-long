/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:35:21 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/02 20:35:36 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
		printstr("(null)", len);
	else
	{
		while (s[i])
		{
			printchar(s[i], len);
			i++;
		}
		return ;
	}
	return ;
}

void	printnbr(long n, int *len, char type)
{
	if (n == -2147483648 && type == 'd')
	{
		printstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		printchar('-', len);
		n *= -1;
	}
	if (n > 9)
	{
		printnbr(n / 10, len, type);
		printnbr(n % 10, len, type);
	}
	else
		printchar(n + 48, len);
}

void	printhexa(unsigned long n, int *len, char type)
{
	char	*base;
	char	hex[20];
	int		indice;

	base = "0123456789abcdef";
	indice = 0;
	if (type == 'p')
		printstr("0x", len);
	if (type == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
	{
		printchar('0', len);
		return ;
	}
	while (n > 0)
	{
		hex[indice] = base[n % 16];
		n = n / 16;
		indice++;
	}
	while (--indice >= 0)
		printchar(hex[indice], len);
}

void	printchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

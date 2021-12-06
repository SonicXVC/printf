/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:28:50 by ameteori          #+#    #+#             */
/*   Updated: 2021/12/06 15:44:38 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	size++;
	if (n < 0)
	{
		size++;
	}
	return (size);
}

int	ft_unsigned_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	size++;
	if (n < 0)
	{
		size++;
	}
	return (size);
}

int	ft_hex(unsigned long long num, char *base)
{
	char	hex[100];
	int		i;
	int		len;

	ft_bzero(hex, 100);
	i = 0;
	while (num / 16)
	{
		*(hex + i) = *(base + (num % 16));
		i++;
		num /= 16;
	}
	*(hex + i) = *(base + (num % 16));
	i++;
	*(hex + i) = '\0';
	len = i - 1;
	while (len > -1)
	{
		ft_putchar_fd(hex[len], 1);
		len--;
	}
	ft_bzero(hex, 100);
	return (i);
}

void	ft_putunsnbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return ;
	if (n > 9)
		ft_putunsnbr_fd((n / 10), 1);
	ft_putchar_fd((n % 10 + '0'), 1);
}

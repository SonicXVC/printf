/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:45:20 by ameteori          #+#    #+#             */
/*   Updated: 2021/12/06 15:42:43 by ameteori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ch(va_list pr)
{
	char	symbol;

	symbol = va_arg(pr, int);
	ft_putchar_fd(symbol, 1);
	return (0);
}

int	ft_str(va_list pr)
{
	char	*str;

	str = va_arg(pr, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)") - 1);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str) - 1);
}

int	ft_digit(va_list pr)
{
	int	dec;

	dec = va_arg(pr, int);
	ft_putnbr_fd(dec, 1);
	return (ft_size(dec) - 1);
}

int	ft_pointer(va_list pr)
{
	unsigned long long	d;

	ft_putstr_fd("0x", 1);
	d = va_arg(pr, unsigned long long);
	return (ft_hex(d, "0123456789abcdef") + 1);
}

int	ft_percent(void)
{
	ft_putchar_fd('%', 1);
	return (0);
}
